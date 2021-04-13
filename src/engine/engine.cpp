#include "engine.hpp"

void Engine::print_2D_vector(std::vector<std::vector<char>> p_matrix) {
    for (std::size_t column = 0; column < p_matrix.size(); ++column) {
        for (std::size_t row = 0; row < p_matrix[column].size(); ++row) {
            std::cout << " " << p_matrix[column][row] << " ";
        }

        std::cout << "\n";
    }
}

void Engine::print_string_vector(std::vector<std::string> p_strings) {
    for (auto index : p_strings) {
        std::cout << index << "\n";
    }
}

std::string Engine::handle_user_input(std::vector<std::string> p_acceptable_input, bool p_verify_input) {
    print_string_vector(p_acceptable_input);

    std::string raw_input;

    std::cin >> raw_input;

    std::vector<std::string> input;

    // For each string in the provided answer vector, check if the user's input matches an option in the vector.
    for (std::string i : p_acceptable_input) {
        if (std::find(p_acceptable_input.begin(), p_acceptable_input.end(), i) != p_acceptable_input.end()) {
            if (i.rfind(raw_input, 0) == 0) input.push_back(i);
        }
    }

    if (input.empty()) {
        std::cout << "Invalid input, please select an appropriate answer." << "\n";
        handle_user_input(p_acceptable_input);
    }

    if (input.size() == 1) {
        if (p_verify_input) {
            std::cout << "Did you choose?: " << input[0] << "\n";

            if (handle_user_input(std::vector<std::string> {"Yes", "No"}, false) == "Yes") {
                return input[0];
            }

            handle_user_input(p_acceptable_input);
        }

        return input[0];
    }

    std::cout << "Which of the following did you mean?: " << "\n";
    handle_user_input(input);

    return "";
}