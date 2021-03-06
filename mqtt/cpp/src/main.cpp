#include "riks_mqtt_client.hpp"

#include "hyker/util/random.hpp"

#include <chrono>
#include <iostream>
#include <thread>

int main() {
    const auto mqtt_host = "mqtt.dev.v2.hykr.io";
    const uint16_t mqtt_port = 1883;
    const auto config = "../../../default.config";

    RiksMQTTClient riks_mqtt_client_1{hyker::util::random_string(16).c_str(), "password", mqtt_host, mqtt_port, config};
    RiksMQTTClient riks_mqtt_client_2{hyker::util::random_string(16).c_str(), "password", mqtt_host, mqtt_port, config};

    const auto topic_name = "SuperSecretSpeakingClock-" + hyker::util::random_string(16);

    riks_mqtt_client_2.subscribe(topic_name, [](std::string content) {
        std::cout << content << '\n';
    });

    while (true) {
        const auto now = std::chrono::system_clock::now().time_since_epoch();;
        const auto timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(now).count();

        riks_mqtt_client_1.publish(topic_name, "The time is: " + std::to_string(timestamp));
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
