#Classe encarregada de gerenciar um movimento do disco
#Armazena o numero do disco, e a haste de destino
class Move
  attr_reader :disk_number
  attr_reader :destination

  def initialize (disk_number, destination)
    @disk_number = disk_number
    @destination = destination
  end
end

#Classe encarregada de armazenar o estado da torre de hanoi
class State
  attr_accessor :peg_map
  attr_accessor :moves

  def initialize (peg_map, moves = [])
    @peg_map = peg_map
    @moves = moves
  end
end

#Classe encarregada de fazer a leitura e a persistencia dos arquivos nas estruturas de dados
class HanoiRead
  def self.read_initial_state_from_file path
    @state_map = {}
    begin
      file = File.new(path, "r")
      while (line = file.gets)
        peg_pair = line.strip.split('-')
        @state_map[peg_pair[0]] = peg_pair[1].split(':')
      end
      file.close
    rescue => err
      puts "Exception: #{err}"
      err
    end
    @state_map
  end

  def self.read_final_state
    @state_map = {}
    position_sets = gets.strip.gsub("\s", "").split(",")
    position_sets.each do | position_set |
      peg_info = position_set.split('-')
      @state_map[peg_info[0]] = peg_info[1..-1]
    end
    @state_map
  end
end

# Classe encarregada de controlar o estado da arvore
#Pega o estado inicial,
# Percorre todas as hastes selecionando o disco superior
# Move esse disco para onde é possível
# Para cada movimento, repetir o algorítmo.
# Condições de parada:
#   - Se não houver mais movimentos possíveis
#   - Se o estado atual é igual ao state_stop
#   - Se o estado atual é igual ao state_start
# Armazenar os movimentos caso a lista seja menor do que a menor lista
# registrada ou se se não houver sido registrada nenhuma.
class HanoiTreeController
  def initialize(start_state, stop_state)
    @start_state = start_state
    @stop_state = stop_state
    @current_minimal_moves = []
  end

  def solve
    run @start_state
    @current_minimal_moves.each do |movex|
      puts "#{movex.disk_number}-#{movex.destination}, "
    end
  end

  def run current_state
    if current_state.peg_map == @stop_state.peg_map
      if(current_minimal_moves == [] or
        current_minimal_moves.length > current_state.moves.length)
        current_minimal_moves = current_state.moves
      end
    end

    current_state.peg_map.each do |peg_id, disks|
      unless(disks.empty?)
        top_disk_number = disks.last
        next if disk_is_on_final_position? peg_id, top_disk_number, disks
        if(current_state.moves.length.zero? or
          current_state.moves.last.disk_number != top_disk_number)
          current_state.peg_map.each do |compared_peg_id, compared_disks|
            unless peg_id == compared_peg_id
              if compared_disks.empty? or compared_disks.last > top_disk_number
                run(move(current_state.dup, peg_id, compared_peg_id))
              end
            end
          end
        end
      end
    end

    if current_state.peg_map == @stop_state.peg_map
      if(current_minimal_moves == [] or
        current_minimal_moves.length > current_state.moves.length)
        current_minimal_moves = current_state.moves
      end
    end
  end

  def move(current_state, move_from, move_to)
    new_move = Move.new(current_state.peg_map[move_from].last, move_to)
    new_peg_map = update_peg_map(current_state.peg_map, move_from, move_to)
    new_moves = current_state.moves.dup
    new_moves << new_move
    State.new(new_peg_map, new_moves)
  end

  def update_peg_map(peg_map, move_from, move_to)
    new_peg_map = {}
    peg_map.each do |key, value|
      new_peg_map[key.dup] = value.dup
    end
    disk_to_move = new_peg_map[move_from].pop
    new_peg_map[move_to] << disk_to_move

    new_peg_map
  end
end

a = HanoiRead.read_initial_state_from_file("data.txt")
b = State.new(a)
c = HanoiRead.read_final_state
d = State.new(c)
e = HanoiTreeController.new(b,d)
e.solve
