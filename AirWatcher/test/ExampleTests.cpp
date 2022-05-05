// #include "../User.h"
// #include "../Sensor.h"
// //#include "../PrivateUser.h"
// #include "../Measurement.h"
// //#include "../Attribute.h"
// #include "../Provider.h"

#include "../Sensor.h"
#include "../Attribute.h"
#include "../Provider.h"
#include "../Cleaner.h"

#include <gtest/gtest.h>


//Partie User
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


//Partie PrivateUser
//test constructor avec paramètres
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

//test setScorePlus1
TEST(PrivateUserTest, setScorePlus1) {
    PrivateUser user("userId", "name", "surname", "email", "password", 1, Unreliable);
    user.setScorePlus1();
    EXPECT_EQ(user.getScore(), 2);
}

//Partie Attribute
//test le constructor vide
TEST(AttributeTest, ConstructorVide) {
    Attribute attribute;
    EXPECT_EQ(attribute.getAttributeId(), "");
    EXPECT_EQ(attribute.getUnit(), "");
    EXPECT_EQ(attribute.getDescription(), "");
}

//test le constructor avec paramètres
TEST(AttributeTest, ConstructorWithParameters) {
    Attribute attribute("attributeId", "unit", "description");
    EXPECT_EQ(attribute.getAttributeId(), "attributeId");
    EXPECT_EQ(attribute.getUnit(), "unit");
    EXPECT_EQ(attribute.getDescription(), "description");
}

//Partie Sensor
//test le constructor avec paramètres
TEST(SensorTest, ConstructorWithParameters) {
    Sensor sensor("sensorId", 1, 2);
    EXPECT_EQ(sensor.getSensorID(), "sensorId");
    EXPECT_EQ(sensor.getLatitude(), 1);
    EXPECT_EQ(sensor.getLongitude(), 2);
    // EXPECT_EQ(sensor.getState(), Unreliable);
}

//test setStateUnreliable
TEST(SensorTest, setStateUnreliable) {
    Sensor sensor("sensorId", 1, 2);
    sensor.SetStateUnreliable();
    EXPECT_EQ(sensor.getState(), Unreliable);
}

//Partie Provider
//test le constructor vide
TEST(ProviderTest, ConstructorVide) {
    Provider provider;
    EXPECT_EQ(provider.getProviderId(), "");
    EXPECT_EQ(provider.getCleanerId(), "");
}

//test le constructor avec paramètres
TEST(ProviderTest, ConstructorWithParameters) {
    Provider provider("providerId", "cleanerId");
    EXPECT_EQ(provider.getProviderId(), "providerId");
    EXPECT_EQ(provider.getCleanerId(), "cleanerId");
}

//Partie Measurement
//test le constructor avec paramètres time_t, double, Attribute
// TEST(MeasurementTest, ConstructorWithParameters) {
//     Measurement measurement(time(NULL), 1.0, Attribute("attributeId", "unit", "description"));
//     EXPECT_EQ(measurement.getTimestamp(), time(NULL));
//     EXPECT_EQ(measurement.getValue(), 1.0);
//     EXPECT_EQ(measurement.getAttribute().getAttributeId(), "attributeId");
//     EXPECT_EQ(measurement.getAttribute().getUnit(), "unit");
//     EXPECT_EQ(measurement.getAttribute().getDescription(), "description");
// }

//Partie Cleaner
//test le constructor avec paramètres
//Cleaner (string cleanerId = "", double latitude = 0.0, double longitude = 0.0, time_t timestampStart = 0, time_t timestampStop = 0);
TEST(CleanerTest, ConstructorWithParameters) {
    Cleaner cleaner("cleanerId", 1.0, 2.0, time(NULL), time(NULL));
    EXPECT_EQ(cleaner.getCleanerId(), "cleanerId");
    EXPECT_EQ(cleaner.getLatitude(), 1.0);
    EXPECT_EQ(cleaner.getLongitude(), 2.0);
    EXPECT_EQ(cleaner.getTimestampStart(), time(NULL));
    EXPECT_EQ(cleaner.getTimestampStop(), time(NULL));
}








