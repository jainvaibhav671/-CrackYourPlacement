class Solution {
public:
    string simplifyPath(string path) {
        vector<string> folders;
        int n = path.length();

        // append a slash at the end
        if (path[n-1] != '/') path += '/';
        cout << path << endl;

        int start = -1;
        int dotCount = 0;
        for (int i = 0; i < path.length(); i++) {
            if (path[i] == '/') {

                // ignore if only one dot
                if (dotCount == 1 && i - start == 1) {
                    start = i + 1;
                    dotCount = 0;
                    continue;
                } else if (dotCount == 2 && i - start == 2) {
                    // go back one directory
                    if (!folders.empty()) {
                        // cout << "POP: " << folders.back() << endl;
                        folders.pop_back();
                    }
                    start = i + 1;
                    dotCount = 0;
                    continue;
                }

                if (start == -1) {
                    // mark the start of the name of the directory
                    start = i + 1;
                } else if (start == i) {
                    // if multipel /s found
                    start++;
                } else {
                    // cout << start << " " << i << endl;
                    // store this directory's name
                    // cout << "PUSH: " << path.substr(start, i - start) << endl;
                    folders.push_back(path.substr(start, i - start));
                    dotCount = 0;
                    start = i + 1;
                }

            } else if (path[i] == '.')
                dotCount++;
        }

        for (auto x : folders) cout << x << " ";
        cout << endl;

        string newPath = "";
        for (auto folder : folders) newPath += '/' + folder;

        return newPath.length() == 0 ? "/" : newPath;
    }
};

// /home//foo