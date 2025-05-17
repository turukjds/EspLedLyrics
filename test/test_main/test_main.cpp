#include <Arduino.h>
#include <unity.h>

// It's good practice to define setup and teardown functions, even if empty.
void setUp(void) {
    // This function is called before each test.
}

void tearDown(void) {
    // This function is called after each test.
}

void test_example_basic_assertion(void) {
    TEST_ASSERT_TRUE(true); // A simple test that should always pass
}

void test_example_another_assertion(void) {
    int a = 5;
    int b = 2 + 3;
    TEST_ASSERT_EQUAL_INT(a, b); // A simple equality test
}

// Standard Arduino setup and loop for running tests on-target
#ifdef ARDUINO

void setup() {
    // Wait for >2 secs if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN(); // IMPORTANT LINE! Initialize Unity test framework
    
    RUN_TEST(test_example_basic_assertion);
    RUN_TEST(test_example_another_assertion);
}

void loop() {
    // For on-target tests, UNITY_END() is typically called to finalize tests.
    // This simple implementation runs tests once in setup.
    // If you need tests to run continuously or be triggered, modify loop().
    static bool tests_finalized = false;
    if (!tests_finalized) {
        UNITY_END(); // Finalize and print results
        tests_finalized = true;
    }
    // You can put other non-test related code here if needed,
    // or leave the loop to do nothing after tests are done.
}

#endif // ARDUINO