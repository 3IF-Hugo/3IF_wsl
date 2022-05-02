#include "../User.h"

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

//Test constructeur avec paramètres user
TEST(UserTest, ConstructorWithParameters) {
    User user("userId", "name", "surname", "email", "password");
    EXPECT_EQ(user.getUserId(), "userId");
    EXPECT_EQ(user.getName(), "name");
    EXPECT_EQ(user.getSurname(), "surname");
    EXPECT_EQ(user.getMail(), "email");
    EXPECT_EQ(user.getPassword(), "password");
}


// TEST(PrivateUser, Getters) {
//     PrivateUser user("userId", "name", "surname", "email", "password", 1, Unreliable);
//     EXPECT_EQ(user.getUserId(), "userId");
//     EXPECT_EQ(user.getName(), "name");
//     EXPECT_EQ(user.getSurname(), "surname");
//     EXPECT_EQ(user.getMail(), "email");
//     EXPECT_EQ(user.getPassword(), "password");
//     EXPECT_EQ(user.getScore(), 1);
//     EXPECT_EQ(user.getStatut(), Unreliable);
// }

//test the constructor
// TEST(PrivateUser, Constructor) {
//     PrivateUser user;
//     EXPECT_EQ(user.getUserId(), "");
//     EXPECT_EQ(user.getName(), "");
//     EXPECT_EQ(user.getSurname(), "");
//     EXPECT_EQ(user.getMail(), "");
//     EXPECT_EQ(user.getPassword(), "");
//     EXPECT_EQ(user.getScore(), 0);
//     EXPECT_EQ(user.getStatut(), Reliable);
// }

//test the constructor with parameters
// TEST(PrivateUser, ConstructorWithParameters) {
//     PrivateUser user("userId", "name", "surname", "email", "password", 1, Unreliable);
//     EXPECT_EQ(user.getUserId(), "userId");
//     EXPECT_EQ(user.getName(), "name");
//     EXPECT_EQ(user.getSurname(), "surname");
//     EXPECT_EQ(user.getMail(), "email");
//     EXPECT_EQ(user.getPassword(), "password");
//     EXPECT_EQ(user.getScore(), 1);
//     EXPECT_EQ(user.getStatut(), Unreliable);
// }