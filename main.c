#include <stdio.h>
#include <curl/curl.h>

// URL-encode a string
char* urlencode(const char* str)
{
    CURL* curl = curl_easy_init();
    char* encoded = curl_easy_escape(curl, str, 0);
    curl_easy_cleanup(curl);
    return encoded;
}

// URL-decode a string
char* urldecode(const char* url)
{
    CURL* curl = curl_easy_init();
    char* decoded = curl_easy_unescape(curl, url, 0, NULL);
    curl_easy_cleanup(curl);
    return decoded;
}

int main() {
	const char* str = "Hello, world! 👋";
    
    // Encode the string
    char* encoded = urlencode(str);
    
    // Print the encoded string
    printf("%s\n", encoded);
    
    // Free the memory allocated by curl_easy_escape
    // curl_free(encoded);
    
    // Decode the URL
    char* decoded = urldecode(encoded);
    
    // Print the decoded string
    printf("%s\n", decoded);
    
    // Free the memory allocated by curl_easy_unescape
    curl_free(decoded);
    
    return 0;
}
