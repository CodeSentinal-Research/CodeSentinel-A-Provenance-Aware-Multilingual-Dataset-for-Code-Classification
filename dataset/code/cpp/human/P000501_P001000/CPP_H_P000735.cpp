#ifndef SLM_H
#define SLM_H
#include <string>
#include <unordered_map>
#include <vector>
#include <random>

class SLM {
public:
    // Construct an empty model
    SLM();

    // Train model using text and k (k-gram length)
    // Throws std::invalid_argument if k <= 0 or k > text.size()
    void train(const std::string& text, int k);

    // Generate count characters from the trained model.
    // Returns generated string of length 'count' (may be empty on error).
    std::string generate(int count);

    // Optional: set RNG seed for reproducibility
    void seed(unsigned int s);

    // Check whether model is trained
    bool is_trained() const;

private:
    int k_; // k-gram length
    std::unordered_map<std::string, int> kgram_count_;
    std::unordered_map<std::string, std::unordered_map<char,int>> transitions_;

    // vectors used for sampling starting k-gram
    std::vector<std::string> kgrams_list_;
    std::vector<int> kgrams_weights_;

    std::mt19937 rng_;

    void build_sampling_vectors();
};

#endif // SLM_H
