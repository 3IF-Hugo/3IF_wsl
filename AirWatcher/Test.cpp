//Classe de test de la classe PrivateUser

//create google test framework
#include <googletest-main/googletest/include/gtest/gtest.h>

//include the class to test
#include "PrivateUser.h"

//test the constructor
TEST(PrivateUser, Constructor) {
    PrivateUser user;
    EXPECT_EQ(user.getUserId(), "");
    EXPECT_EQ(user.getName(), "");
    EXPECT_EQ(user.getSurname(), "");
    EXPECT_EQ(user.getMail(), "");
    EXPECT_EQ(user.getPassword(), "");
    EXPECT_EQ(user.getScore(), 0);
    EXPECT_EQ(user.getStatut(), Reliable);
}

//test the constructor with parameters
TEST(PrivateUser, ConstructorWithParameters) {
    PrivateUser user("userId", "name", "surname", "email", "password", 1, Unreliable);
    EXPECT_EQ(user.getUserId(), "userId");
    EXPECT_EQ(user.getName(), "name");
    EXPECT_EQ(user.getSurname(), "surname");
    EXPECT_EQ(user.getMail(), "email");
    EXPECT_EQ(user.getPassword(), "password");
    EXPECT_EQ(user.getScore(), 1);
    EXPECT_EQ(user.getStatut(), Unreliable);
}

//test the constructor with parameters
TEST(PrivateUser, ConstructorWithParameters2) {
    PrivateUser user("userId", "name", "surname", "email", "password", 1, Reliable);
    EXPECT_EQ(user.getUserId(), "userId");
    EXPECT_EQ(user.getName(), "name");
    EXPECT_EQ(user.getSurname(), "surname");
    EXPECT_EQ(user.getMail(), "email");
    EXPECT_EQ(user.getPassword(), "password");
    EXPECT_EQ(user.getScore(), 1);
    EXPECT_EQ(user.getStatut(), Reliable);
}

//test the constructor with