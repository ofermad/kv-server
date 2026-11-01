#include <gtest/gtest.h>
#include "storage.h"

TEST(StorageTest, GetMissingKeyReturnsNullopt) {
    Storage storage;
    EXPECT_FALSE(storage.Get("missing").has_value());
}

TEST(StorageTest, SetOverwritesExistingValue) {
    Storage storage;
    storage.Set("key", "old");
    storage.Set("key", "new");
    EXPECT_EQ(storage.Get("key"), "new");
}

TEST(StorageTest, DelReturnsFalseForMissingKey) {
    Storage storage;
    EXPECT_FALSE(storage.Del("missing"));
}

TEST(StorageTest, DelRemovesExistingKey) {
    Storage storage;
    storage.Set("key", "value");
    EXPECT_TRUE(storage.Del("key"));
    EXPECT_FALSE(storage.Get("key").has_value());
}

TEST(StorageTest, EmptyValueIsStored) {
    Storage storage;
    storage.Set("key", "");
    EXPECT_EQ(storage.Get("key"), "");
}

TEST(StorageTest, EmptyKeyIsAllowed) {
    Storage storage;
    storage.Set("", "value");
    EXPECT_EQ(storage.Get(""), "value");
}