#pragma once
#include <Arduino.h>
#include <HTTPClient.h>

class Firebase
{
public:
	static String post(const char *Path, String Payload);
	static String patch(const char *Path, String Payload);
	static String put(const char *Path, String Payload);
};
