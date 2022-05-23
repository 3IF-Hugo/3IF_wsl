// #include "../User.h"
// #include "../Sensor.h"
// //#include "../PrivateUser.h"
// #include "../Measurement.h"
// //#include "../Attribute.h"
// #include "../Provider.h"

#include "../User.h"
#include "../PrivateUser.h"
#include "../Sensor.h"
#include "../Attribute.h"
#include "../Lecture.h"
#include "../Service.h"
//#include "../Measurement.h"
#include "../Provider.h"
#include "../Cleaner.h"
#include "../UtilityService.h"
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
    PrivateUser user1("userId", "name", "surname", "email", "password", 1, "sensor1", Unreliable);
    EXPECT_EQ(user1.getUserId(), "userId");
    EXPECT_EQ(user1.getName(), "name");
    EXPECT_EQ(user1.getSurname(), "surname");
    EXPECT_EQ(user1.getMail(), "email");
    EXPECT_EQ(user1.getPassword(), "password");
    EXPECT_EQ(user1.getScore(), 1);
    EXPECT_EQ(user1.getSensorId(), "sensor1");
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
    PrivateUser user("userId", "name", "surname", "email", "password", 1, "sensor1", Unreliable);
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
TEST(MeasurementTest, ConstructorWithParameters) {
    Measurement measurement(time(NULL), 1.0, Attribute("attributeId", "unit", "description"));
    EXPECT_EQ(measurement.getTimestamp(), time(NULL));
    EXPECT_EQ(measurement.getValue(), 1.0);
    EXPECT_EQ(measurement.getAttribute().getAttributeId(), "attributeId");
    EXPECT_EQ(measurement.getAttribute().getUnit(), "unit");
    EXPECT_EQ(measurement.getAttribute().getDescription(), "description");
}

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


//Partie UtilityService
//test double * UtilityService::calculateMean(map<string, Sensor> sensors, Sensor sensorRef, time_t date, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10 )
TEST(UtilityServiceTest, CalculateMean) {
    UtilityService utilityService;
    multimap<Sensor, Measurement> mesureO3;
    multimap<Sensor, Measurement> mesureSO2;
    multimap<Sensor, Measurement> mesureNO2;
    multimap<Sensor, Measurement> mesurePM10;

    Sensor sensorO3("sensorO3", 1, 1);
    Sensor sensorSO2("sensorSO2", 1, 1);
    Sensor sensorNO2("sensorNO2", 1, 1);
    Sensor sensorPM10("sensorPM10", 1, 1);

    mesureO3.insert(pair<Sensor, Measurement>(sensorO3, Measurement(time(NULL), 1.0, Attribute("attributeId", "unit", "description"))));
    mesureSO2.insert(pair<Sensor, Measurement>(sensorSO2, Measurement(time(NULL), 1.0, Attribute("attributeId", "unit", "description"))));
    mesureNO2.insert(pair<Sensor, Measurement>(sensorNO2, Measurement(time(NULL), 1.0, Attribute("attributeId", "unit", "description"))));
    mesurePM10.insert(pair<Sensor, Measurement>(sensorPM10, Measurement(time(NULL), 1.0, Attribute("attributeId", "unit", "description"))));

    map<string, Sensor> sensors;
    sensors.insert(pair<string, Sensor>("sensorO3", sensorO3));
    sensors.insert(pair<string, Sensor>("sensorSO2", sensorSO2));
    sensors.insert(pair<string, Sensor>("sensorNO2", sensorNO2));
    sensors.insert(pair<string, Sensor>("sensorPM10", sensorPM10));
    double * mean = utilityService.calculateMean(sensors, sensorO3, time(NULL), mesureO3, mesureSO2, mesureNO2, mesurePM10);
    EXPECT_EQ(mean[0], 0.25);
}

//test double * UtilityService::calculateMean(map<string, Sensor> sensors, Sensor sensorRef,





//bool UtilityService::analyseSensor(map<string, Sensor> allSensors, Sensor sensorAnalyse, double rayon, time_t date, multimap<Sensor,Measurement> mesureO3, multimap<Sensor,Measurement> mesureSO2, multimap<Sensor,Measurement> mesureNO2, multimap<Sensor,Measurement> mesurePM10)
TEST(UtilityServiceTest, analyseSensor) {
    UtilityService utilityService;
    map<string, Sensor> allSensors;
    Sensor sensorAnalyse("sensorAnalyse", 1.0, 2.0);
    allSensors.insert(pair<string, Sensor>("sensorAnalyse", sensorAnalyse));
    double rayon = 1.0;
    time_t date = time(NULL);
    multimap<Sensor, Measurement> mesureO3;
    multimap<Sensor, Measurement> mesureSO2;
    multimap<Sensor, Measurement> mesureNO2;
    multimap<Sensor, Measurement> mesurePM10;
    EXPECT_EQ(utilityService.analyseSensor(allSensors, sensorAnalyse, rayon, date, mesureO3, mesureSO2, mesureNO2, mesurePM10), true);
}

//Partie Lecture
// test bool Lecture::LireDonnees(map<string, Sensor> & listeCapteurs,list<Attribute> & listeAttributs, list<PrivateUser> & listePrivateUsers,
//list<Cleaner> & listeCleaners, list<Provider> & listeProviders,
//multimap<Sensor, Measurement> & mesuresO3, multimap<Sensor, Measurement> & mesuresSO2,
//multimap<Sensor, Measurement> & mesuresNO2, multimap<Sensor, Measurement> & mesuresPM10)
TEST(LectureTest, LireDonnees) {
    Lecture lecture;
    map<string, Sensor> listeCapteurs;
    list<Attribute> listeAttributs;
    list<PrivateUser> listePrivateUsers;
    list<Cleaner> listeCleaners;
    list<Provider> listeProviders;
    multimap<Sensor, Measurement> mesuresO3;
    multimap<Sensor, Measurement> mesuresSO2;
    multimap<Sensor, Measurement> mesuresNO2;
    multimap<Sensor, Measurement> mesuresPM10;
    EXPECT_EQ(lecture.LireDonnees(listeCapteurs, listeAttributs, listePrivateUsers, listeCleaners, listeProviders, mesuresO3, mesuresSO2, mesuresNO2, mesuresPM10), true);
}

//Performance test
//test méthode Lecture::LireDonnees
TEST(PerformanceTest, LireDonnees) {
    Lecture lecture;
    map<string, Sensor> listeCapteurs;
    list<Attribute> listeAttributs;
    list<PrivateUser> listePrivateUsers;
    list<Cleaner> listeCleaners;
    list<Provider> listeProviders;
    multimap<Sensor, Measurement> mesuresO3;
    multimap<Sensor, Measurement> mesuresSO2;
    multimap<Sensor, Measurement> mesuresNO2;
    multimap<Sensor, Measurement> mesuresPM10;
    clock_t start = clock();
    lecture.LireDonnees(listeCapteurs, listeAttributs, listePrivateUsers, listeCleaners, listeProviders, mesuresO3, mesuresSO2, mesuresNO2, mesuresPM10);
    clock_t end = clock();
    double time = (double) (end - start) / CLOCKS_PER_SEC;
    //affiche le temps d'exécution
    cout << "Temps d'exécution : " << time << " secondes" << endl;
    EXPECT_LT(time, 0.5);
}

//test performance service.analyzeSensor
TEST(PerformanceTest, analyzeSensor) {
    UtilityService utilityService;
    map<string, Sensor> allSensors;
    Sensor sensorAnalyse("sensorAnalyse", 1.0, 2.0);
    allSensors.insert(pair<string, Sensor>("sensorAnalyse", sensorAnalyse));
    double rayon = 1.0;
    time_t date = time(NULL);
    multimap<Sensor, Measurement> mesureO3;
    multimap<Sensor, Measurement> mesureSO2;
    multimap<Sensor, Measurement> mesureNO2;
    multimap<Sensor, Measurement> mesurePM10;
    clock_t start = clock();
    utilityService.analyseSensor(allSensors, sensorAnalyse, rayon, date, mesureO3, mesureSO2, mesureNO2, mesurePM10);
    clock_t end = clock();
    double time = (double) (end - start) / CLOCKS_PER_SEC;
    //affiche le temps d'exécution
    cout << "Temps d'exécution : " << time << " secondes" << endl;
    EXPECT_LT(time, 0.5);
}




