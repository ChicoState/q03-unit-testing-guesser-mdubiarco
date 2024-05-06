/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
        protected:
                GuesserTest(){} //constructor runs before each test
                virtual ~GuesserTest(){} //destructor cleans up after tests
                virtual void SetUp(){} //sets up before each test (after constructor)
                virtual void TearDown(){} //clean up after each test, (before destructor)
};

/* Example test
TEST(GuesserTest, smoke_test)
{
    ASSERT_EQ( 1+1, 2 );
}
*/

TEST(GuesserTest,Different_Length)
{       Guesser guess("secret");

        bool result = guess.match("guess_and_secret_length_different");
        ASSERT_EQ(false,result);

}

TEST(GuesserTest, secret_matches)
{       Guesser guess("secret");

        bool count = guess.match("corrcet_secret_length");
        ASSERT_EQ(true,count);

}
TEST(GuesserTest,No_more_guesses_remaining)
{
        Guesser guess("secret");
        guess.match("guess1_incorrect");
        guess.match("guess2_incorrect");
        guess.match("guess3_incorrect");

        bool result = guess.match("secret");
        ASSERT_EQ(false,result);

}
TEST(GuesserTest, One_Correct_Guess)
{       Guesser guess("secret");

        bool result_1 = guess.match("guess1_incorrect");
        bool result_2 = guess.match("secret");
        ASSERT_EQ(false,result_1);
        ASSERT_EQ(true,result_2);
        ASSERT_EQ(3,guess.remaining());
}