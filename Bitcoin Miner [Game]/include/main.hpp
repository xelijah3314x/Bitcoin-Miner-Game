#include <iostream>
#include <windows.h>

using namespace std;

namespace game {
    string gameVersion = "V1.0";
    string gameState = "Menu";

    double btc = 0;
    double eth = 0;
    double rvn = 0;

    int btcMiners = 0;
    int ethMiners = 0;
    int rvnMiners = 0;

    double btcDifficulty = 1;
    double ethDifficulty = 5;
    double rvnDifficulty = 15;
    
    auto currentCrypto = &btc;
    auto mCurrentCrypto = *currentCrypto;
    string sCurrentCrypto = "BTC";

    auto currentCryptoMiners = &btcMiners;
    auto mCurrentCryptoMiners = *currentCryptoMiners;

    auto currentCryptoDifficulty = &btcDifficulty;
    auto mCurrentCryptoDifficulty = *currentCryptoDifficulty;

    void input() {
        if (gameState == "Menu") {
            if (GetAsyncKeyState('1')) {
                gameState = "Play";
            } else if (GetAsyncKeyState('2')) {
                gameState = "Controls";
            } else if (GetAsyncKeyState('3')) {
                gameState = "Credits";
            } else if (GetAsyncKeyState('4')) {
                gameState = "Exit";
            }
        }

        if (gameState == "Controls") {
            if (GetAsyncKeyState('1')) {
                gameState = "Menu";
            }
        }

        if (gameState == "Credits") {
            if (GetAsyncKeyState('1')) {
                gameState = "Menu";
            }
        }

        if (gameState == "Exit") {
            if (GetAsyncKeyState('1')) {
                exit(3);
            } else if (GetAsyncKeyState('2')) {
                gameState = "Menu";
            }
        }

        if (gameState == "Play") {
            if (GetAsyncKeyState('F')) {
                mCurrentCrypto += (1 / mCurrentCryptoDifficulty);
            }

            if (GetAsyncKeyState('R')) {
                if (mCurrentCrypto >= (mCurrentCryptoMiners + 1) * (25 + mCurrentCryptoDifficulty - 1)) {
                    mCurrentCrypto -= (mCurrentCryptoMiners + 1) * (25 + mCurrentCryptoDifficulty - 1);
                    mCurrentCryptoMiners += 1;
                }
            }
        }
    }

    void update() {
        for (int index = 0; index < mCurrentCryptoMiners; index++) {
            mCurrentCrypto += (1 / mCurrentCryptoDifficulty);
        }
    }

    void draw() {
        system("cls");

        if (gameState == "Menu") {
            cout << "Bitcoin Miner " << gameVersion << endl << endl;

            cout << "1: Play" << endl;
            cout << "2: Controls" << endl;
            cout << "3: Credits" << endl;
            cout << "4: Exit" << endl;
        }

        if (gameState == "Controls") {
            cout << "Controls" << endl << endl;

            cout << "Tap 'F' to start mining crypto. Press 'R' to purchase a crypto miner. Use numbers 1-9 to switch between crypto currencies." << endl << endl;

            cout << "1: Back" << endl;
        }

        if (gameState == "Credits") {
            cout << "Credits" << endl << endl;

            cout << "This game was made by Elijah33#0001 on discord!" << endl << endl;

            cout << "1: Back" << endl;
        }

        if (gameState == "Exit") {
            cout << "Are you sure you want to exit?" << endl << endl;

            cout << "1: Yes" << endl;
            cout << "2: No" << endl;
        }

        if (gameState == "Play") {
            cout << "Current Crypto: ";
            system("Color E");
            cout << sCurrentCrypto << endl;
            system("Color 7");
            
            cout << "Coins: ";
            system("Color A");
            cout << mCurrentCrypto << endl;
            system("Color 7");


            cout << "Miners: ";
            system("Color 3");
            cout << mCurrentCryptoMiners;
            system("Color 7");
            cout << " (Next Miner Cost: " << (mCurrentCryptoMiners + 1) * (25 + mCurrentCryptoDifficulty - 1) << ")" << endl << endl;
        }
    }
}