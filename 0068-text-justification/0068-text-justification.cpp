class Solution { 
public: 
    int MAX_Width; 

    string findline(int i, int j, int& eachgaddhaspace, 
                    int& extraspace, vector<string>& words) { 

        string line;

        for (int k = i; k < j; k++) { 
            line += words[k];

            // Don't add spaces after the last word
            if (k != j - 1) {

                for (int z = 1; z <= eachgaddhaspace; z++) { 
                    line += " "; 
                }

                if (extraspace > 0) { 
                    line += " "; 
                    extraspace--; 
                } 
            }
        }

        while (line.length() < MAX_Width) { 
            line += " "; 
        }

        return line;
    } 

    vector<string> fullJustify(vector<string>& words, int maxWidth) { 

        MAX_Width = maxWidth;

        int n = words.size();
        vector<string> result;
        int i = 0; 

        while (i < n) { 

            int lettercount = words[i].length();
            int j = i + 1; 
            int gaddhe = 0;

            while (j < n && 
                   words[j].length() + 1 + gaddhe + lettercount <= maxWidth) {

                lettercount += words[j].length();
                gaddhe += 1;
                j++;
            }

            int remainslot = maxWidth - lettercount;

            int eachgaddhaspace = 0;
            int extraspace = 0;

            if (gaddhe > 0) {
                eachgaddhaspace = remainslot / gaddhe;
                extraspace = remainslot % gaddhe;
            }

            // Last line
            if (j == n) { 
                eachgaddhaspace = 1; 
                extraspace = 0; 
            }

            result.push_back(
                findline(i, j, eachgaddhaspace, extraspace, words)
            );

            i = j;
        }

        return result;
    }
};