#ifndef UNITY_H
#define UNITY_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Unity Test Result Types */
typedef enum {
    UNITY_DISPLAY_STYLE_INT,
    UNITY_DISPLAY_STYLE_UINT,
    UNITY_DISPLAY_STYLE_HEX8,
    UNITY_DISPLAY_STYLE_HEX16,
    UNITY_DISPLAY_STYLE_HEX32,
    UNITY_DISPLAY_STYLE_CHAR
} UNITY_DISPLAY_STYLE_T;

/* Unity Internal Variables */
extern int Unity_TestsRun;
extern int Unity_TestsFailed;
extern int Unity_CurrentTestFailed;

/* Unity Test Functions */
void UnityBegin(const char* filename);
int UnityEnd(void);
void UnityPrint(const char* string);
void UnityPrintLen(const char* string, const uint32_t length);
void UnityPrintNumberByStyle(const long number, const UNITY_DISPLAY_STYLE_T style);
void UnityTestResultsBegin(const char* file, const uint32_t line);
void UnityTestResultsFailBegin(const uint32_t line);
void UnityConcludeTest(void);

void UnityAssertEqualNumber(const long expected,
                          const long actual,
                          const char* msg,
                          const uint32_t lineNumber,
                          const UNITY_DISPLAY_STYLE_T style);

void UnityAssertEqualIntArray(const int* expected,
                            const int* actual,
                            const uint32_t num_elements,
                            const char* msg,
                            const uint32_t lineNumber,
                            const UNITY_DISPLAY_STYLE_T style);

void UnityAssertBits(const long mask,
                   const long expected,
                   const long actual,
                   const char* msg,
                   const uint32_t lineNumber);

void UnityAssertEqualString(const char* expected,
                          const char* actual,
                          const char* msg,
                          const uint32_t lineNumber);

void UnityAssertEqualStringLen(const char* expected,
                             const char* actual,
                             const uint32_t length,
                             const char* msg,
                             const uint32_t lineNumber);

void UnityAssertEqualStringArray(const char** expected,
                               const char** actual,
                               const uint32_t num_elements,
                               const char* msg,
                               const uint32_t lineNumber);

void UnityAssertEqualMemory(const void* expected,
                          const void* actual,
                          const uint32_t length,
                          const uint32_t num_elements,
                          const char* msg,
                          const uint32_t lineNumber);

void UnityAssertNumbersWithin(const long delta,
                            const long expected,
                            const long actual,
                            const char* msg,
                            const uint32_t lineNumber,
                            const UNITY_DISPLAY_STYLE_T style);

void UnityFail(const char* msg, const uint32_t line);

void UnityIgnore(const char* msg, const uint32_t line);

/* Unity Macros */
#define UNITY_TEST_ASSERT_EQUAL_INT(expected, actual, line, message) \
    UnityAssertEqualNumber((long)(expected), (long)(actual), (message), (uint32_t)(line), UNITY_DISPLAY_STYLE_INT)

#define UNITY_TEST_ASSERT_EQUAL_STRING(expected, actual, line, message) \
    UnityAssertEqualString((const char*)(expected), (const char*)(actual), (message), (uint32_t)(line))

#define UNITY_TEST_ASSERT_NULL(pointer, line, message) \
    UnityAssertEqualNumber((long)0, (long)(pointer), (message), (uint32_t)(line), UNITY_DISPLAY_STYLE_INT)

#define UNITY_TEST_ASSERT_NOT_NULL(pointer, line, message) \
    if ((pointer) == 0) UnityFail((message), (uint32_t)(line))

#define UNITY_TEST_FAIL(line, message) \
    UnityFail((message), (uint32_t)(line))

/* User Friendly Macros */
#define TEST_ASSERT_EQUAL_INT(expected, actual) \
    UNITY_TEST_ASSERT_EQUAL_INT((expected), (actual), __LINE__, NULL)

#define TEST_ASSERT_EQUAL_STRING(expected, actual) \
    UNITY_TEST_ASSERT_EQUAL_STRING((expected), (actual), __LINE__, NULL)

#define TEST_ASSERT_NULL(pointer) \
    UNITY_TEST_ASSERT_NULL((pointer), __LINE__, NULL)

#define TEST_ASSERT_NOT_NULL(pointer) \
    UNITY_TEST_ASSERT_NOT_NULL((pointer), __LINE__, NULL)

#define TEST_ASSERT_TRUE(condition) \
    UNITY_TEST_ASSERT_EQUAL_INT(1, (condition) ? 1 : 0, __LINE__, "Expected TRUE")

#define TEST_ASSERT_FALSE(condition) \
    UNITY_TEST_ASSERT_EQUAL_INT(0, (condition) ? 1 : 0, __LINE__, "Expected FALSE")

#define TEST_FAIL() \
    UNITY_TEST_FAIL(__LINE__, NULL)

#define TEST_FAIL_MESSAGE(message) \
    UNITY_TEST_FAIL(__LINE__, (message))

/* Test Setup */
#define RUN_TEST(func) \
    Unity_CurrentTestFailed = 0; \
    UnityTestResultsBegin(__FILE__, __LINE__); \
    UnityPrint(#func); \
    func(); \
    UnityConcludeTest()

#ifdef __cplusplus
}
#endif

#endif /* UNITY_H */ 