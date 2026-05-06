#pragma once 
#include <cmath>

struct CelestialBody {
  double radius;
  double mass;
  double mu;
};


constexpr double G = 6.674e-11;

// Earth
constexpr CelestialBody Earth {
    6.37e6,
    5.97e24,
    3.984e14
};
// ☀️ Kerbol
constexpr CelestialBody Kerbol {
    2.616e8,
    1.756e28,
    1.172e18
};

// ☿ Moho
constexpr CelestialBody Moho {
    2.5e5,
    2.526e21,
    1.684e11
};

// ♀ Eve
constexpr CelestialBody Eve {
    7.0e5,
    1.23e23,
    8.204e12
};

// 🪐 Kerbin
constexpr CelestialBody Kerbin {
    6e5,
    5.2915158e22,
    3.5316e12
};

// 🔴 Duna
constexpr CelestialBody Duna {
    3.2e5,
    4.515e21,
    3.012e11
};

// 🪨 Dres
constexpr CelestialBody Dres {
    1.38e5,
    3.219e20,
    2.147e10
};

// 🟠 Jool
constexpr CelestialBody Jool {
    6.0e6,
    4.233e24,
    2.822e14
};

// 🌕 Laythe
constexpr CelestialBody Laythe {
    5.0e5,
    2.94e22,
    1.961e12
};

// 🌕 Vall
constexpr CelestialBody Vall {
    3.0e5,
    3.1e21,
    2.068e11
};

// 🌕 Tylo
constexpr CelestialBody Tylo {
    6.0e5,
    4.25e22,
    2.834e12
};

// 🌕 Bop
constexpr CelestialBody Bop {
    6.5e4,
    3.726e19,
    2.485e9
};

// 🌕 Pol
constexpr CelestialBody Pol {
    4.4e4,
    1.081e19,
    7.214e8
};

// ❄️ Eeloo
constexpr CelestialBody Eeloo {
    2.1e5,
    1.114e21,
    7.442e10
};
