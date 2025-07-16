#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

void sendIntegers(HANDLE hSerial, int data1) {
    char buffer[40];  // Assuming two 4-byte integers, leave some space for safety
    snprintf(buffer, sizeof(buffer), "%d ", data1);

    DWORD bytesWritten;
    if (!WriteFile(hSerial, buffer, strlen(buffer), &bytesWritten, NULL)) {
        fprintf(stderr, "Error writing to serial port\n");
        CloseHandle(hSerial);
        exit(EXIT_FAILURE);
    }

}

void sendInteger1(HANDLE hSerial, int data2) {
    char buffer[40];  // Assuming two 4-byte integers, leave some space for safety
    snprintf(buffer, sizeof(buffer), "%d ", data2);

    DWORD bytesWritten;
    if (!WriteFile(hSerial, buffer, strlen(buffer), &bytesWritten, NULL)) {
        fprintf(stderr, "Error writing to serial port\n");
        CloseHandle(hSerial);
        exit(EXIT_FAILURE);
    }

}
int receiveResponse(HANDLE hSerial) {
    char buffer[256];
    DWORD bytesRead;

    if (!ReadFile(hSerial, buffer, sizeof(buffer), &bytesRead, NULL)) {
        fprintf(stderr, "Error reading from serial port\n");
        CloseHandle(hSerial);
        exit(EXIT_FAILURE);
    }

    buffer[bytesRead] = '\0';  // Null-terminate the received data
    printf("Arduino response: %s\n", buffer);

    // Veriyi tamsayıya çevir
    int arduinoResponse = atoi(buffer);

    return arduinoResponse;
}

int main() {
    HANDLE hSerial;
    DCB dcbSerialParams = {0};
    COMMTIMEOUTS timeouts = {0};

    // Open the serial port
    hSerial = CreateFile("COM3", GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (hSerial == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Error opening serial port\n");
        return 1;
    }

    // Set the serial port parameters
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams)) {
        fprintf(stderr, "Error getting serial port state\n");
        CloseHandle(hSerial);
        return 1;
    }

    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    if (!SetCommState(hSerial, &dcbSerialParams)) {
        fprintf(stderr, "Error setting serial port state\n");
        CloseHandle(hSerial);
        return 1;
    }

    // Set timeouts
    timeouts.ReadIntervalTimeout = 50;
    timeouts.ReadTotalTimeoutConstant = 50;
    timeouts.ReadTotalTimeoutMultiplier = 10;
    timeouts.WriteTotalTimeoutConstant = 50;
    timeouts.WriteTotalTimeoutMultiplier = 10;

    if (!SetCommTimeouts(hSerial, &timeouts)) {
        fprintf(stderr, "Error setting timeouts\n");
        CloseHandle(hSerial);
        return 1;
    }

    // Send two integers to Arduino
    int integer1ToSend = -1;
    int integer2ToSend;
    while(integer1ToSend != 0){
    printf("## WELCOME TO GTU ARDUINO LAB        ##\n");
    printf("## STUDENT NAME: GABIL RAHIMLI       ##\n");
    printf("## PLEASE SELECT FROM THE FOLLOWING  ##\n");
    printf("## MENU :                            ##\n\n");
    printf("(1) TURN ON LED ON ARDUINO\n");
    printf("(2) TURN OFF LED ON ARDUINO\n");
    printf("(3) FLASH ARDUINO LED 5 TIMES\n");
    printf("(4) SEND A NUMBER TO ARDUINO TO COMPUTE FACTORIAL BY ARDUINO\n");
    printf("(5) Button press counter (bonus item)\n");
    printf("(6) Turn on external led (bonus item)\n");
    printf("(0) EXIT\n");

    printf("PLEASE SELECT: \n");
    scanf(" %d",&integer1ToSend);

    sendIntegers(hSerial, integer1ToSend);
    if(integer1ToSend == 1){
        printf("LED IS HIGH \n");
    }
     if(integer1ToSend == 2){
        printf("LED IS LOW \n");
    }
    if(integer1ToSend == 4){
    printf("PLEASE ENTER NUMBER: \n");
    scanf(" %d",&integer2ToSend);
    sendIntegers(hSerial, integer2ToSend);
    int arduinoResponse = receiveResponse(hSerial);

    }
     if (integer1ToSend == 5) {
            printf("Arduino: Buton Basi Sayi: %d\n", receiveResponse(hSerial));
        }
    }


    // Receive and print Arduino's response
    int arduinoResponse = receiveResponse(hSerial);

    // Close the serial port
    CloseHandle(hSerial);

    return 0;
}
