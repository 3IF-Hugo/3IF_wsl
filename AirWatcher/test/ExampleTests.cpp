#include "../User.h"
#include "../PrivateUser.h"

#include <gtest/gtest.h>

//test des getters de user
TEST(UserTest, Getters) {
    User user("userId", "name", "surname", "email", "password");
    EXPECT_EQ(user.getUserId(), "userId");
    EXPECT_EQ(user.getName(), "name");
    EXPECT_EQ(user.getSurname(), "surname");
    EXPECT_EQ(user.getMail(), "email");
    EXPECT_EQ(user.getPassword(), "password");
}

//test le constructor vide
TEST(UserTest, ConstructorVide) {
    User user;
    EXPECT_EQ(user.getUserId(), "");
    EXPECT_EQ(user.getName(), "");
    EXPECT_EQ(user.getSurname(), "");
    EXPECT_EQ(user.getMail(), "");
    EXPECT_EQ(user.getPassword(), "");
}

//Test constructeur avec paramètres user
TEST(UserTest, ConstructorWithParameters) {
    User user("userId", "name", "surname", "email", "password");
    EXPECT_EQ(user.getUserId(), "userId");
    EXPECT_EQ(user.getName(), "name");
    EXPECT_EQ(user.getSurname(), "surname");
    EXPECT_EQ(user.getMail(), "email");
    EXPECT_EQ(user.getPassword(), "password");
}


TEST(PrivateUserTest, ConstructorWithParameters) {
    PrivateUser user1("userId", "name", "surname", "email", "password", 1, Unreliable);
    EXPECT_EQ(user1.getUserId(), "userId");
    EXPECT_EQ(user1.getName(), "name");
    EXPECT_EQ(user1.getSurname(), "surname");
    EXPECT_EQ(user1.getMail(), "email");
    EXPECT_EQ(user1.getPassword(), "password");
    EXPECT_EQ(user1.getScore(), 1);
    EXPECT_EQ(user1.getStatut(), Unreliable);
}

//test le constructor vide
TEST(PrivateUserTest, ConstructorVide) {
    PrivateUser user;
    EXPECT_EQ(user.getUserId(), "");
    EXPECT_EQ(user.getName(), "");
    EXPECT_EQ(user.getSurname(), "");
    EXPECT_EQ(user.getMail(), "");
    EXPECT_EQ(user.getPassword(), "");
    EXPECT_EQ(user.getScore(), 0);
    EXPECT_EQ(user.getStatut(), Reliable);
}