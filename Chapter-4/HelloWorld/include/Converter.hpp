//
// Created by iZastic on 11/15/2015.
//

#ifndef SFML_BLUEPRINTS_CONVERTER_HPP
#define SFML_BLUEPRINTS_CONVERTER_HPP

namespace converter
{
    constexpr double PIXELS_PER_METER = 32.0;
    constexpr double PI = 3.14159265358979323846;

    template<typename T>
    constexpr T pixelsToMeters(const T &x) { return x / PIXELS_PER_METER; }

    template<typename T>
    constexpr T metersToPixels(const T &x) { return x * PIXELS_PER_METER; }

    template<typename T>
    constexpr T degToRad(const T &x) { return PI * x / 180.0; }

    template<typename T>
    constexpr T radToDeg(const T &x) { return 180.0 * x / PI; }
}

#endif //SFML_BLUEPRINTS_CONVERTER_HPP
