#include "unity.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Unity Internal Variables */
int Unity_TestsRun = 0;
int Unity_TestsFailed = 0;
int Unity_CurrentTestFailed = 0;

/* Begin Test Session */
void UnityBegin(const char* filename) {
    Unity_TestsRun = 0;
    Unity_TestsFailed = 0;
    UnityPrint("Unity test run for ");
    UnityPrint(filename);
    UnityPrint("\n");
}

/* End Test Session */
int UnityEnd(void) {
    UnityPrint("\n-----------------------\n");
    UnityPrintNumberByStyle(Unity_TestsRun, UNITY_DISPLAY_STYLE_INT);
    UnityPrint(" Tests ");
    UnityPrintNumberByStyle(Unity_TestsFailed, UNITY_DISPLAY_STYLE_INT);
    UnityPrint(" Failures ");
    UnityPrintNumberByStyle(Unity_TestsRun - Unity_TestsFailed, UNITY_DISPLAY_STYLE_INT);
    UnityPrint(" Ignored\n");
    
    if (Unity_TestsFailed == 0) {
        UnityPrint("OK\n");
    } else {
        UnityPrint("FAIL\n");
    }
    
    return Unity_TestsFailed;
}

/* Print Functions */
void UnityPrint(const char* string) {
    if (string) {
        printf("%s", string);
    }
}

void UnityPrintLen(const char* string, const uint32_t length) {
    if (string) {
        printf("%.*s", (int)length, string);
    }
}

void UnityPrintNumberByStyle(const long number, const UNITY_DISPLAY_STYLE_T style) {
    switch (style) {
        case UNITY_DISPLAY_STYLE_INT:
            printf("%ld", number);
            break;
        case UNITY_DISPLAY_STYLE_UINT:
            printf("%lu", (unsigned long)number);
            break;
        case UNITY_DISPLAY_STYLE_HEX8:
            printf("0x%02lX", (unsigned long)number & 0xFF);
            break;
        case UNITY_DISPLAY_STYLE_HEX16:
            printf("0x%04lX", (unsigned long)number & 0xFFFF);
            break;
        case UNITY_DISPLAY_STYLE_HEX32:
            printf("0x%08lX", (unsigned long)number);
            break;
        case UNITY_DISPLAY_STYLE_CHAR:
            printf("'%c'", (char)number);
            break;
    }
}

/* Test Result Functions */
void UnityTestResultsBegin(const char* file, const uint32_t line) {
    UnityPrint(file);
    UnityPrint(":");
    UnityPrintNumberByStyle(line, UNITY_DISPLAY_STYLE_INT);
    UnityPrint(":");
}

void UnityTestResultsFailBegin(const uint32_t line) {
    UnityPrint("FAIL: Line ");
    UnityPrintNumberByStyle(line, UNITY_DISPLAY_STYLE_INT);
    UnityPrint(": ");
}

void UnityConcludeTest(void) {
    Unity_TestsRun++;
    if (Unity_CurrentTestFailed) {
        Unity_TestsFailed++;
        UnityPrint(" FAIL\n");
    } else {
        UnityPrint(" PASS\n");
    }
}

/* Assert Functions */
void UnityAssertEqualNumber(const long expected,
                          const long actual,
                          const char* msg,
                          const uint32_t lineNumber,
                          const UNITY_DISPLAY_STYLE_T style) {
    if (expected != actual) {
        Unity_CurrentTestFailed = 1;
        UnityTestResultsFailBegin(lineNumber);
        UnityPrint("Expected ");
        UnityPrintNumberByStyle(expected, style);
        UnityPrint(" Was ");
        UnityPrintNumberByStyle(actual, style);
        if (msg) {
            UnityPrint(". ");
            UnityPrint(msg);
        }
        UnityPrint("\n");
    }
}

void UnityAssertEqualString(const char* expected,
                          const char* actual,
                          const char* msg,
                          const uint32_t lineNumber) {
    if (expected == NULL && actual == NULL) {
        return; // Both NULL, they're equal
    }
    
    if (expected == NULL || actual == NULL || strcmp(expected, actual) != 0) {
        Unity_CurrentTestFailed = 1;
        UnityTestResultsFailBegin(lineNumber);
        UnityPrint("Expected \"");
        if (expected) {
            UnityPrint(expected);
        } else {
            UnityPrint("NULL");
        }
        UnityPrint("\" Was \"");
        if (actual) {
            UnityPrint(actual);
        } else {
            UnityPrint("NULL");
        }
        UnityPrint("\"");
        if (msg) {
            UnityPrint(". ");
            UnityPrint(msg);
        }
        UnityPrint("\n");
    }
}

void UnityAssertEqualStringLen(const char* expected,
                             const char* actual,
                             const uint32_t length,
                             const char* msg,
                             const uint32_t lineNumber) {
    if (expected == NULL && actual == NULL) {
        return; // Both NULL, they're equal
    }
    
    if (expected == NULL || actual == NULL || strncmp(expected, actual, length) != 0) {
        Unity_CurrentTestFailed = 1;
        UnityTestResultsFailBegin(lineNumber);
        UnityPrint("Expected \"");
        if (expected) {
            UnityPrintLen(expected, length);
        } else {
            UnityPrint("NULL");
        }
        UnityPrint("\" Was \"");
        if (actual) {
            UnityPrintLen(actual, length);
        } else {
            UnityPrint("NULL");
        }
        UnityPrint("\"");
        if (msg) {
            UnityPrint(". ");
            UnityPrint(msg);
        }
        UnityPrint("\n");
    }
}

void UnityFail(const char* msg, const uint32_t line) {
    Unity_CurrentTestFailed = 1;
    UnityTestResultsFailBegin(line);
    if (msg) {
        UnityPrint(msg);
    } else {
        UnityPrint("Test Failed");
    }
    UnityPrint("\n");
}

void UnityIgnore(const char* msg, const uint32_t line) {
    Unity_CurrentTestFailed = 1;
    UnityTestResultsFailBegin(line);
    UnityPrint("IGNORE: ");
    if (msg) {
        UnityPrint(msg);
    } else {
        UnityPrint("Test Ignored");
    }
    UnityPrint("\n");
}

/* Stub implementations for unused functions */
void UnityAssertEqualIntArray(const int* expected,
                            const int* actual,
                            const uint32_t num_elements,
                            const char* msg,
                            const uint32_t lineNumber,
                            const UNITY_DISPLAY_STYLE_T style) {
    (void)expected; (void)actual; (void)num_elements; (void)msg; (void)lineNumber; (void)style;
}

void UnityAssertBits(const long mask,
                   const long expected,
                   const long actual,
                   const char* msg,
                   const uint32_t lineNumber) {
    (void)mask; (void)expected; (void)actual; (void)msg; (void)lineNumber;
}

void UnityAssertEqualStringArray(const char** expected,
                               const char** actual,
                               const uint32_t num_elements,
                               const char* msg,
                               const uint32_t lineNumber) {
    (void)expected; (void)actual; (void)num_elements; (void)msg; (void)lineNumber;
}

void UnityAssertEqualMemory(const void* expected,
                          const void* actual,
                          const uint32_t length,
                          const uint32_t num_elements,
                          const char* msg,
                          const uint32_t lineNumber) {
    (void)expected; (void)actual; (void)length; (void)num_elements; (void)msg; (void)lineNumber;
}

void UnityAssertNumbersWithin(const long delta,
                            const long expected,
                            const long actual,
                            const char* msg,
                            const uint32_t lineNumber,
                            const UNITY_DISPLAY_STYLE_T style) {
    (void)delta; (void)expected; (void)actual; (void)msg; (void)lineNumber; (void)style;
} 