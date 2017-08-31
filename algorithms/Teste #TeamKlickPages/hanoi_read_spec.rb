#hanoi_read_spec.rb_

require_relative 'hanoi.rb'

describe "read_initial_state_from_file" do
  it "Transforms the file content into a data structure" do
    imported_data = HanoiRead.read_initial_state_from_file("data.txt")
    expect(imported_data).to eq(
    "A" => ["4", "1"], "B" => ["3"], "C" => ["2"]
    )
  end

  describe "read_final_state" do
    let(:position_sets) {"A-1, B-4-2, C-3"}

    it "get an input and define the final state map" do
      input = HanoiRead.read_final_state(position_sets)
      expect(input).to include(
      "A"=>["1"], "B"=>["4", "2"], "C"=>["3"]
      )
    end
  end
end
