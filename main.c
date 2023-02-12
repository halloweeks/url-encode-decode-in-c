#include <stdio.h>
#include <stdlib.h>
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
char* urldecode(const char* str)
{
    CURL* curl = curl_easy_init();
    int outlen = 0;
    char* decoded = curl_easy_unescape(curl, str, 0, &outlen);
    curl_easy_cleanup(curl);
    return decoded;
}

int main()
{
    const char* str = "Hello, world!";
    
    // Encode the string
    char* encoded = urlencode(str);
    
    // Print the encoded string
    printf("Encoded: %s\n", encoded);
    
    // Decode the string
    char* decoded = urldecode(encoded);
    
    // Print the decoded string
    printf("Decoded: %s\n", decoded);
    
    // Free the memory allocated by curl_easy_escape and curl_easy_unescape
    curl_free(encoded);
    curl_free(decoded);
    
    return 0;
}
