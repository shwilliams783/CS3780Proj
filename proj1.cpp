#include <cmath>
#include <openssl/sha.h>
#include <openssl/md5.h>
#include <openssl/rand.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

#define SIZE 100
using namespace std;

void newAccount();
void logIn();

int main() {
	int choice;
		
	cout << "1) Create account\n2) Log in\nPlease enter choice:";
	std::cin >> choice;
	
	switch(choice)
	{
		case 1: 
			cout << "Creating new account.\n";
			newAccount();
			break;
		case 2:
			cout << "Logging in.\n";
			logIn();
			break;
		default:
			cout << "Invalid choice.\n";
			return 0;
	}
	return 0;
}

void newAccount()
{
	
	char user[SIZE];
	char pass[SIZE];
	unsigned char ubuf[SIZE];
	unsigned char pbuf[SIZE];
	unsigned char MD5Buf[SIZE];
	char MD5BufHex[SIZE];
	unsigned char SHA256Buf[SIZE];
	char SHA256BufHex[SIZE];
	unsigned char SHA256SaltBuf[SIZE];
	char SHA256SaltBufHex[SIZE];
	unsigned char Salt[SIZE];
	
	
	cout << "Please enter username:";
	cin >> user;
	for (int i = 0; i < 100; i++) {
		ubuf[i] = user[i];
	}
	
	cout << "Please enter 3-digit password:";
	cin >> pass;
	for (int i = 0; i < 100; i++) {
		pbuf[i] = pass[i];
	}
	
	MD5(pbuf, strlen(pass), MD5Buf);
	ofstream MD5File;
	MD5File.open("passwdmd5", ios::out | ios::app );
	MD5File << user;
	MD5File << ",";
	for(int i = 0; i<32; i++){
        sprintf(MD5BufHex, "%02X", MD5Buf[i]);
		MD5File << MD5BufHex;
    }
	MD5File << "\n";
	MD5File.close();
	
	SHA256(pbuf, strlen(pass), SHA256Buf);
	ofstream SHA256File;
	SHA256File.open("passwdSHA256", ios::out | ios::app );
	SHA256File << user;
	SHA256File << ",";
	for(int i = 0; i<32; i++){
        sprintf(SHA256BufHex, "%02X", SHA256Buf[i]);
		SHA256File << SHA256BufHex;
    }
	SHA256File << "\n";
	SHA256File.close();

	RAND_bytes(Salt, sizeof 4);
	for(int i = 0; i<4; i++){
		pbuf[i+3] = Salt[i]; 
	}
	SHA256(pbuf, strlen(pass)+4, SHA256SaltBuf);
	ofstream SHA256SaltFile;
	SHA256SaltFile.open("passwdSHA256Salt", ios::out | ios::app );
	SHA256SaltFile << user;
	SHA256SaltFile << ",";
	for(int i = 0; i<32; i++){
        sprintf(SHA256SaltBufHex, "%02X", SHA256SaltBuf[i]);
		SHA256SaltFile << SHA256SaltBufHex;
    }
	SHA256SaltFile << ",";
	for (int i = 0; i < 4; i++) {
		sprintf(SHA256SaltBufHex, "%02X", Salt[i]);
		SHA256SaltFile << SHA256SaltBufHex;
	}
	SHA256SaltFile << "\n";
	SHA256SaltFile.close();	
}

void logIn()
{
	char orig[SIZE];
	unsigned char ibuf[SIZE];
}
