#include <Firebase.h>

HTTPClient http;

String Firebase::post(const char *Path, String Payload) {
    http.begin(Path);
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.POST(Payload);

    if (httpResponseCode > 0) {
        String result = http.getString();
        Serial.print("Post Result: ");
        Serial.println(result);
        return result;
    } else {
        Serial.print("Error: ");
        Serial.println(httpResponseCode);
        return String(httpResponseCode);
    }
}

String Firebase::patch(const char *Path, String Payload) {
    http.begin(Path);
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.PATCH(Payload);

    if (httpResponseCode > 0) {
        String result = http.getString();
        Serial.print("Patch Result: ");
        Serial.println(result);
        return result;
    } else {
        Serial.print("Error: ");
        Serial.println(httpResponseCode);
        return String(httpResponseCode);
    }
}

String Firebase::put(const char *Path, String Payload) {
    http.begin(Path);
    http.addHeader("Content-Type", "application/json");

    int httpResponseCode = http.PUT(Payload);

    if (httpResponseCode > 0) {
        String result = http.getString();
        Serial.print("Put Result: ");
        Serial.println(result);
        return result;
    } else {
        Serial.print("Error: ");
        Serial.println(httpResponseCode);
        return String(httpResponseCode);
    }
}
