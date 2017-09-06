import unittest
from my_hanoi import *

class TestStringMethods(unittest.TestCase):

    def test_reading_initial_state_from_file(self):
        expected_input = {'A': ['4', '3', '2', '1'], 'C': [''], 'B': ['']}
        self.assertEqual(readInitialState("testes-unitarios/teste-input.txt"), expected_input)

    def test_check_disk_wrong_order(self):
        wrong_order_initial_state = readInitialState("testes-unitarios/teste-input-wrong-order.txt")
        self.assertFalse(checkDisksOrder(wrong_order_initial_state))

    def test_check_disk_correct_order(self):
        correct_input = readInitialState("testes-unitarios/teste-input.txt")
        self.assertTrue(checkDisksOrder(correct_input))

    def test_check_states_non_equal(self):
        initial_state = {'A': ['4', '3', '2', '1'], 'C': [''], 'B': ['']}
        final_state = {'A': ['4', '3'], 'C': ['2'], 'B': ['3']}
        self.assertFalse(checkStatesEquality(initial_state, final_state))

    def test_check_states_are_equal(self):
        initial_state = {'A': ['4', '3'], 'C': ['2'], 'B': ['3']}
        final_state = {'A': ['4', '3'], 'C': ['2'], 'B': ['3']}
        self.assertTrue(checkStatesEquality(initial_state, final_state))


if __name__ == '__main__':
    unittest.main()
