#include <iostream>
#include <chrono>

// Function to get the current time since program start in seconds (as float)
float getCurrentTimeInSeconds() {
    static const auto start = std::chrono::high_resolution_clock::now();
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);
    return float (duration.count()) / 1000.0f;// Convert milliseconds to seconds
}
float calculateDeltatime(float &prev, float &current){
        float delta = current - prev;
        prev = current;
        return delta;
}
void calculateFps(int &seconds, int &secondsPrev, int &frames, float &current, int &fps){
    seconds = current;
        if (seconds > secondsPrev){
            fps = frames;
            secondsPrev = seconds;
            frames = 0;
        }
}
int main() {
    float prev = 0;
    float current = 0;
    int frames = 0;
    int fps = 0;
    int seconds = 0;
    int secondsPrev = 0;
    while(true){
        frames++;
        current = getCurrentTimeInSeconds();
        calculateFps(seconds, secondsPrev, frames, current, fps);
        float deltaTime = calculateDeltatime(prev, current);
        std:: cout << "fps      : "<< fps << "\n";
        std:: cout << "deltaTime: "<< deltaTime << "\n";
        for (int i = 0; i < 100000000; i++){

        }
    }
    return 0;
}