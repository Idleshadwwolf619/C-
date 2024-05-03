#include <iostream>        // Provides input/output operations
#include <string>          // Provides string handling functions
#include <vector>          // Provides the vector container
#include <algorithm>       // Provides algorithms like find_if
#include <sstream>         // Provides string stream operations

std::vector<std::string> TokenizeString(const std::string& input) {
    std::vector<std::string> tokens;                    // Create a vector to store tokens
    std::string token;                                  // Create a string to store each token
    std::istringstream iss(input);                      // Create a string stream from the input string
    while (iss >> token) {                              // Loop through the stream, extracting tokens
        tokens.push_back(token);                        // Add each token to the vector
    }
    return tokens;                                      // Return the vector of tokens
}

bool ContainsWord(const std::string& input, const std::string& word) {
    std::vector<std::string> tokens = TokenizeString(input);  // Tokenize the input string
    return std::find_if(tokens.begin(), tokens.end(), [&](const std::string& token) {
        return token.find(word) != std::string::npos;         // Check if the word is present in any token
        }) != tokens.end();                                       // Return true if the word is found, false otherwise
}

std::string GetBotResponse(const std::string& userInput) {
    static bool readyForWaffles = false;                   // Static flag to track if the user is ready for waffles
    static bool exploringWaffleInfo = false;               // Static flag to track if the user is exploring waffle info

    std::string input = userInput;
    std::transform(input.begin(), input.end(), input.begin(), ::tolower);  // Convert the input string to lowercase

    if (!readyForWaffles) {
        // Check if the user greeted
        if (ContainsWord(input, "hello") || ContainsWord(input, "hi")) {
            return "Hi there! Are you ready to embark on a waffle adventure? (yes/no)";
        }
        // Check if the user is ready for waffles
        else if (ContainsWord(input, "yes")) {
            readyForWaffles = true;
            return "Great! Let's dive into the delicious world of waffles. Would you like a waffle recipe or some waffle facts? (recipe/facts)";
        }
        // Check if the user is not ready for waffles
        else if (ContainsWord(input, "no")) {
            return "That's alright! Take your time. Feel free to ask me anything whenever you're ready.";
        }
        else {
            return "Hey there, waffle enthusiast! Are you ready for some waffles? (yes/no)";
        }
    }
    else {
        // Check if the user is exploring waffle info
        if (!exploringWaffleInfo) {
            // Check if the user wants a waffle recipe
            if (ContainsWord(input, "recipe")) {
                exploringWaffleInfo = true;
                return  "Sure! Here's a simple waffle recipe:\n\nIngredients:\n- 2 cups all-purpose flour\n- 2 tablespoons sugar\n- 1 tablespoon baking powder\n- 1/2 teaspoon salt\n- 1 3/4 cups milk\n- 1/3 cup vegetable oil\n- 2 large eggs\n\nInstructions:\n1. Preheat your waffle iron.\n2. In a large bowl, whisk together the flour, sugar, baking powder, and salt.\n3. In another bowl, whisk together the milk, vegetable oil, and eggs.\n4. Pour the wet ingredients into the dry ingredients and stir until just combined.\n5. Lightly grease the waffle iron with cooking spray or melted butter.\n6. Pour the batter onto the preheated waffle iron and cook according to the manufacturer's instructions.\n7. Serve the waffles warm with your favorite toppings.\n\nEnjoy your homemade waffles!\n\nDo you want more waffle recipes or waffle facts? (recipe/facts/no)";
            }
            // Check if the user wants waffle facts
            else if (ContainsWord(input, "facts")) {
                exploringWaffleInfo = true;
                return  "Did you know? The world's largest waffle weighed over 110 pounds! That's a whole lot of deliciousness!\n\nDo you want more waffle recipes or waffle facts? (recipe/facts/no)";
            }
            // Check if the user doesn't want more waffle info
            else if (ContainsWord(input, "no")) {
                readyForWaffles = false;
                return "Alright, no problem! Feel free to ask me anything else. Enjoy your day!";
            }
            else {
                return "I'm here to help you with waffles! Would you like a waffle recipe or some waffle facts? (recipe/facts/no)";
            }
        }
        else {
            // Check if the user wants another waffle recipe
            if (ContainsWord(input, "recipe")) {
                return  "Sure! Here's a simple waffle recipe:\n\nIngredients:\n- 2 cups all-purpose flour\n- 2 tablespoons sugar\n- 1 tablespoon baking powder\n- 1/2 teaspoon salt\n- 1 3/4 cups milk\n- 1/3 cup vegetable oil\n- 2 large eggs\n\nInstructions:\n1. Preheat your waffle iron.\n2. In a large bowl, whisk together the flour, sugar, baking powder, and salt.\n3. In another bowl, whisk together the milk, vegetable oil, and eggs.\n4. Pour the wet ingredients into the dry ingredients and stir until just combined.\n5. Lightly grease the waffle iron with cooking spray or melted butter.\n6. Pour the batter onto the preheated waffle iron and cook according to the manufacturer's instructions.\n7. Serve the waffles warm with your favorite toppings.\n\nEnjoy your homemade waffles!\n\nDo you want more waffle recipes or waffle facts? (recipe/facts/no)";
            }
            // Check if the user wants more waffle facts
            else if (ContainsWord(input, "facts")) {
                return  "Did you know? The world's largest waffle weighed over 110 pounds! That's a whole lot of deliciousness!\n\nDo you want more waffle recipes or waffle facts? (recipe/facts/no)";
            }
            // Check if the user doesn't want more waffle info
            else if (ContainsWord(input, "no")) {
                readyForWaffles = false;
                exploringWaffleInfo = false;
                return "Alright, no problem! Feel free to ask me anything else. Enjoy your day!";
            }
            else {
                return "I'm here to help you with waffles! Would you like a waffle recipe or some waffle facts? (recipe/facts/no)";
            }
        }
    }
}

int main() {
    std::cout << "Welcome to WaffleBot! The sweetest chatbot in the universe." << std::endl;

    while (true) {
        std::string userInput;
        std::cout << "User: ";
        std::getline(std::cin, userInput);                      // Get user input

        std::string botResponse = GetBotResponse(userInput);    // Get response from the bot
        std::cout << "WaffleBot: " << botResponse << std::endl;  // Print bot's response

        if (ContainsWord(userInput, "quit") || ContainsWord(userInput, "exit")) {
            break;  // Exit the loop if user wants to quit
        }
    }

    return 0;
}