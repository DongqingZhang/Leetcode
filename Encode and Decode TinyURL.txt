class Solution {
public:
    string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> depo;
    unordered_map<string, string> depo2;
    int id = -1;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        id++;
        string shortUrl;
        while(id){
            shortUrl+=dict[id%62];
            id/=62;
        }
        depo[longUrl] = shortUrl;
        depo2[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(depo2.find(shortUrl) == depo2.end()) return "";
        return depo2[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));