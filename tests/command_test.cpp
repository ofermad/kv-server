#include <gtest/gtest.h>
#include "command.h"

TEST(CommandTest, ParsesSet) {
    ParseResult res = ParseCommand("SET key value");

    ASSERT_TRUE(res.command.has_value());
    EXPECT_EQ(res.command->type, Command::Type::Set);
    EXPECT_EQ(res.command->key, "key");
    EXPECT_EQ(res.command->value, "value");
}

TEST(CommandTest, UnknownCommandIsError) {
    ParseResult res = ParseCommand("Put key value");

    EXPECT_FALSE(res.command.has_value());
    EXPECT_EQ(res.error, "unknown command: Put");
}

TEST(CommandTest, WrongArgumentCountIsErrorForSet) {
    ParseResult res = ParseCommand("SET key value SS");

    EXPECT_FALSE(res.command.has_value());
    EXPECT_EQ(res.error, "wrong number of arguments for SET");
}

TEST(CommandTest, WrongArgumentCountIsErrorForGet) {
    ParseResult res = ParseCommand("GET key value");

    EXPECT_FALSE(res.command.has_value());
    EXPECT_EQ(res.error, "wrong number of arguments for GET");
}

TEST(CommandTest, WrongArgumentCountIsErrorForDel) {
    ParseResult res = ParseCommand("DEL key value");

    EXPECT_FALSE(res.command.has_value());
    EXPECT_EQ(res.error, "wrong number of arguments for DEL");
}

TEST(CommandTest, ToUpperCaseForSet) {
    ParseResult res = ParseCommand("sEt key value");

    ASSERT_TRUE(res.command.has_value());
    EXPECT_EQ(res.command->type, Command::Type::Set);
    EXPECT_EQ(res.command->key, "key");
    EXPECT_EQ(res.command->value, "value");
}

TEST(CommandTest, ToUpperCaseForGet) {
    ParseResult res = ParseCommand("gEt key");

    ASSERT_TRUE(res.command.has_value());
    EXPECT_EQ(res.command->type, Command::Type::Get);
    EXPECT_EQ(res.command->key, "key");
}

TEST(CommandTest, ToUpperCaseForDel) {
    ParseResult res = ParseCommand("dEl key");

    ASSERT_TRUE(res.command.has_value());
    EXPECT_EQ(res.command->type, Command::Type::Del);
    EXPECT_EQ(res.command->key, "key");
}