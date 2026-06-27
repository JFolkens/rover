#include <gtest/gtest.h>

#include "rover/brain/drive_command.h"
#include "rover/brain/mock_chassis.h"

namespace rover::tests::brain {

TEST(DriveCommandTest, InitializesWithIdleIntent) {
    rover::brain::DriveCommand cmd;
    
    EXPECT_EQ(cmd.intent, rover::brain::Intent::Idle);
    EXPECT_EQ(cmd.speed, 0);
    EXPECT_EQ(cmd.turn_factor, 0);
}

TEST(MockChassisTest, RecordsForwardDrive) {
    rover::brain::MockChassis chassis;
    
    chassis.driveForward(50);
    
    EXPECT_EQ(chassis.lastForwardSpeed(), 50);
    EXPECT_FALSE(chassis.wasStopped());
}

TEST(MockChassisTest, RecordsReverseDrive) {
    rover::brain::MockChassis chassis;
    
    chassis.driveReverse(30);
    
    EXPECT_EQ(chassis.lastReverseSpeed(), 30);
    EXPECT_FALSE(chassis.wasStopped());
}

TEST(MockChassisTest, RecordsStop) {
    rover::brain::MockChassis chassis;
    
    chassis.driveForward(75);
    chassis.stop();
    
    EXPECT_TRUE(chassis.wasStopped());
    EXPECT_EQ(chassis.lastForwardSpeed(), 0);
}

TEST(MockChassisTest, TracksEncoderTicks) {
    rover::brain::MockChassis chassis;
    
    chassis.setEncoderTicks(0, 100);
    chassis.setEncoderTicks(1, 105);
    chassis.setEncoderTicks(2, 98);
    chassis.setEncoderTicks(3, 102);
    
    EXPECT_EQ(chassis.getEncoderTicks(0), 100);
    EXPECT_EQ(chassis.getEncoderTicks(1), 105);
    EXPECT_EQ(chassis.getEncoderTicks(2), 98);
    EXPECT_EQ(chassis.getEncoderTicks(3), 102);
}

TEST(MockChassisTest, ResetsEncoders) {
    rover::brain::MockChassis chassis;
    
    chassis.setEncoderTicks(0, 50);
    chassis.setEncoderTicks(1, 60);
    chassis.resetEncoders();
    
    EXPECT_EQ(chassis.getEncoderTicks(0), 0);
    EXPECT_EQ(chassis.getEncoderTicks(1), 0);
}

}  // namespace rover::tests::brain
