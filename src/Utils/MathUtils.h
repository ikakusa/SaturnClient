#pragma once
template <typename T>
struct vec2 {
public:
	T x;
	T y;
public:
	vec2() : x(0), y(0) { };
	vec2(T x, T y) : x(x), y(y) {};
};

template <typename T>
struct vec3 {
public:
	T x;
	T y;
	T z;
public:
	vec3() : x(0), y(0), z(0) { };
	vec3(T x, T y, T z) : x(x), y(y), z(z) {};
};

template <typename T>
struct vec4 {
public:
	T x;
	T y;
	T z;
	T w;
public:
	vec4() : x(0), y(0), z(0), w(0) { };
	vec4(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {};
};