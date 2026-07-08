#include <windows.h>
#include <iostream>
#include <string>

// Source - https://stackoverflow.com/a/8196291
// Posted by Beached
// Retrieved 2026-07-08, License - CC BY-SA 3.0
BOOL IsElevated() {
    BOOL fRet = FALSE;
    HANDLE hToken = NULL;
    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
        TOKEN_ELEVATION Elevation;
        DWORD cbSize = sizeof(TOKEN_ELEVATION);
        if (GetTokenInformation(hToken, TokenElevation, &Elevation, sizeof(Elevation), &cbSize)) {
            fRet = Elevation.TokenIsElevated;
        }
    }
    if (hToken) {
        CloseHandle(hToken);
    }
    return fRet;
}

int main() {
    DWORD pid = GetCurrentProcessId();
    BOOL isAdmin = IsElevated();

    std::string architecture;
#if defined(_WIN64)
    architecture = "x64 (64-bit)";
#elif defined(_WIN32)
    architecture = "x86 (32-bit)";
#else
    architecture = "Unknown";
#endif

    std::string privLevel = isAdmin ? "Administrator" : "User";

    std::cout << "=========================================\n";
    std::cout << "         OFFENSIVE SYNTAX: DUMMY         \n";
    std::cout << "=========================================\n";
    std::cout << "[+] Process ID   : " << pid << "\n";
    std::cout << "[+] Architecture : " << architecture << "\n";
    std::cout << "[+] Privileges   : " << privLevel << "\n";
    std::cout << "=========================================\n";
    std::cout << "[*] Waiting... (Press Enter to exit)\n";

    std::cin.get();

    return 0;
}