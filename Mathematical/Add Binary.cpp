class Solution {

    pair<char, char> add(char dig1, char dig2, char carry) {
        char x = '0';
        if (dig1 == '1' && dig2 == '1') {
            if (carry == '0') {
                x = '0';
                carry = '1';
            } else x = '1';
        } else if (dig1 == '1' || dig2 == '1') {
            if (carry == '0') x = '1';
            else {
                x = '0';
                carry = '1';
            }
        } else {
            x = carry;
            carry = '0';
        }

        return { x, carry };
    }

public:
    string addBinary(string a, string b) {
        int an = a.length();
        int bn = b.length();

        // pad zeroes
        if (an > bn) {
            for (int i=0; i<(an-bn); i++) b = '0' + b;
        } else {
            for (int i=0; i<(bn-an); i++) a = '0' + a;
        }

        int i = max(an, bn) - 1;

        string res = "";
        char carry = '0';
        while (i >= 0) {
            char dig1 = a[i],
                 dig2 = b[i];
            
            auto [x, c] = add(dig1, dig2, carry);
            carry = c;

            i--;
            res = x + res;
        }

        if (carry == '1') res = carry + res;

        return res;
    }
};