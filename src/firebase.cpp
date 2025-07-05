#include <Firebase.h>

HTTPClient http;

void updateStatus(char *Path, int Status)
{
	http.begin(Path);
	http.addHeader("Content-Type", "application/json");
	http.addHeader("Connection", "keep-alive");
	http.addHeader("Accept-Encoding", "gzip, deflate, br");

	String payload = "{";

	payload.concat("\"status\":");
	payload.concat(Status);
	payload.concat("}");

	int httpResponseCode = http.PATCH(payload);
	if (httpResponseCode > 0)
	{
		String result = http.getString();
		Serial.print("Result: ");
		Serial.println(result);
	}
}