CREATE SCHEMA heavid;

USE heavid;

CREATE TABLE Exercise
    (ExerciseID INT NOT NULL AUTO_INCREMENT,
    ExerciseName VARCHAR(45) NOT NULL,
    Description TEXT NOT NULL,
    DifficultyLevel ENUM('Beginner', 'Intermediate', 'Advanced') NOT NULL,
    CONSTRAINT Exercise_pk PRIMARY KEY (ExerciseID)
) engine = innodb;

CREATE TABLE Muscle_Group
    (MuscleID INT NOT NULL AUTO_INCREMENT,
    MuscleName VARCHAR(25),
    CONSTRAINT Muscle_Group_pk PRIMARY KEY (MuscleID)
) engine = innodb;

CREATE TABLE Exercise_Has_Muscle
    (Exercise_ExerciseID INT NOT NULL,
    Muscle_Group_MuscleID INT NOT NULL,
    UNIQUE KEY (Exercise_ExerciseID, Muscle_Group_MuscleID),
    CONSTRAINT Exercise_Has_Muscle_fk1 FOREIGN KEY (Exercise_ExerciseID) REFERENCES Exercise(ExerciseID),
    CONSTRAINT Exercise_Has_Muscle_fk2 FOREIGN KEY (Muscle_Group_MuscleID) REFERENCES Muscle_Group(MuscleID)
) engine = innodb;

CREATE TABLE Exercise_Image
    (ImageID INT NOT NULL AUTO_INCREMENT,
    Exercise_ExerciseID INT NOT NULL,
    Image LONGBLOB,
    CONSTRAINT Exercise_Image_pk PRIMARY KEY (ImageID),
    CONSTRAINT Exercise_Image_fk FOREIGN KEY (Exercise_ExerciseID) REFERENCES Exercise(ExerciseID)
) engine = innodb;


insert into Exercise(ExerciseName, Description, DifficultyLevel) values
('Squats','Stand facing forward with your chest up. Place your feet shoulder-width apart. Bend at your knees and hips, sticking your butt out. Squat down as low as you can while maintaining your head and chest lifted.', 'Beginner'),
('Jump Squats','Stand tall with your feet hip-width apart. Hinge at the hips to push your butt back and lower down until your thighs are parallel to the floor. Allow your knees to bend 45 degrees when you land. Immediately drop back down into a squat and jump again.', 'Intermediate'),
('Pistol Squats','Extend one leg in front of you, as straight as you can, while keeping core tight. Bend your standing leg and lower your body, extending your other leg out in front of you.', 'Advanced'),
('Calf Raises','Stand straight up, then push through the balls of your feet and raise your heel until you are standing on your toes.',  'Beginner'),
('Single-Leg Calf Raises','Balance on one foot then push through the balls of your feet and raise feet until you are standing on your toes.', 'Intermediate'),
('Single-Leg Calf Jumps', 'Balance on one foot then jump up, landing on the balls of your feet.',  'Advanced'),
('Glute Bridges','Have knees above the ankles when you come up. Lift up while the core is engaged, making sure no overarching the back. Lower back stays pressed on the ground when coming down.' , 'Beginner'),
('Single-Leg Glute Bridges','Position yourself as if you are doing a regular glute bridge. Instead having both legs on the ground, set up with one leg out creating a straight line, while engaging your core.', 'Intermediate'),
('Single-Leg Glute Bridge with hold','Perform the single-leg glute bridge but hold the extension at the top for 5 seconds.', 'Advanced'),

('Russian Twist','Sit with bent knees, hold your hands next to your chest. Sit back slightly, keeping your spine straight. Exhale as you twist to the right, bringing your left arms over to the right side. Return back to center, and perform the opposite side.', 'Beginner'),
('Crunches', 'Lie down on your back. Plant your feet on the floor. Bend your knees and place arms across your chest. Exhale and lift your upper body, keeping your head and neck relaxed.',  'Intermediate'),
('Bicycles','Lift one leg just off the ground and extend it out. Lift the other leg and bend your knee towards your chest. Twist your core so the opposite arm comes towards the raised knee.','Intermediate'),
('Flutter Kicks','Lie on your back and extend your legs up to a 45 degree angle. Raise your lower leg and lower the other, focusing on keeping your core engaged.',  'Advanced'),
('Leg Pull-In Knee-ups','Lie flat with your hands off to the side. Keep your knees together and pull them in towards you while moving your torso towards them. Hold and then slowly return to starting position.', 'Advanced'),
('Inchworms','Start in a push-up position and walk your hands to your feet. Come back to either a standing position or just to your toes.',  'Advanced'),
('Lying Leg Raises','Place your hands underneath your lower back and glutes so your pelvis is supported. Begin to raise your legs toward the ceiling, keeping the legs straight. Then lower back down and repeat.', 'Advanced'),
('Mountain Climbers','Start from a high plank and drive one knee forward toward your chest while engaging your abs. Return to plank position, then drive opposite knee in. Speed up this process',  'Beginner'),
('Plank Jacks','Start in low plank position. Jump both feet out wide to each side as if you were doing a horizontal jumping jacks.',  'Advanced'),
('Toe Touches','Lay on your back while keeping your legs pointed to the ceiling. Engage the core while you come up to touch your toes.',  'Intermediate'),
('Shoulder Tap Plank','Start in a high plank position. Keeping your hips as still as possible, lift one hand and tap it on the opposite shoulder. Then repeat on the other side.',  'Beginner'),
('Elbow Plank', 'Place your hands and forearms on the ground and drive your hips up toward the ceiling so your body forms a straight line from your ankles to shoulders.',  'Intermediate'),
('Sit-ups','Lie on your back. Bend your legs and place feet firmly on the ground. Cross your hands to opposite shoulders. Curl your upper body all the way up toward your knees.','Beginner'),
('V-ups', 'Lie fully extended and your arms extended over your head. Raise both legs and torso simultaneously and reach toward your feet. Return to starting position and repeat.',  'Advanced'),
('Side planks','Turn your body to the side and perform a plank either placing your forearm or hand for stability.','Intermediate'),
('Side star planks','Start in side plank but lift the top leg up and hold this position.', 'Advanced'),
 
('Modified Push-ups','Start at the top of the push up position. Step your knees back behind so there is a straight line through your body from your knees to head. Engage your glutes and brace your core to keep your body controlled as you go down.', 'Beginner'),
('Push-ups','Place your hands slightly wider than your shoulders while straighten your arms and legs. Lower your body until your chest nearly touches the floor. Pause, then push yourself back up.', 'Intermediate'),
('Decline Push-ups','Place your hands on the floor, shoulders over your wrist and place your feet on a bench. Brace your core, glutes, and quads. Push into the floor to return to starting position, extending your elbows.', 'Advanced'),
('Reverse Fly','Stand with feet hip-width apart, knees slightly bent. Slowly spread your arms apart to a T-shape. Move slowly and with control bringing your arms back to parallel position.',  'Beginner'),
('Tricep Dips', 'Take your full body weight onto your arms, bending your knees so your feet are off the ground. Bend your elbows and lower your body slowly. Go as low as you can without feeling discomfort in your shoulders.', 'Beginner'),
('Negative pull-up','Grab a stable object like a bench or a box to stand underneath the pull-up bar. Grip the pull-up bar with both hands and jump off the bench and pull yourself up. With control, slowly lower your body down counting for 5 seconds until your arms are fully extended at the bottom.',  'Beginner'),
('Pull-ups with resistance band','Grab a resistance band and wrap it around the pull-up bar. Get your foot through the center of the band. Now pull yourself up over the bar.', 'Intermediate'),
('Pull-ups','Engage the muscles in your arms and back, bend your elbows and raise your upper body. Avoid swinging your legs around or shrugging your shoulders up.','Advanced'),
('Push-up Shoulder Taps','Perform a push-up. As you come up, left hand taps your right shoulder then right hand taps your left then perform another push-up. Repeat.',  'Advanced'),
('Modified Diamond Push-ups','Position your hands close together, spreading your fingers to create a diamond shape with your index fingers. Begin to lower your chest to the floor while keeping your back flat.',  'Advanced');

insert into Muscle_Group(MuscleName) values ('Lower Body'),('Core'),('Upper Body');


insert into Exercise_Has_Muscle(Exercise_ExerciseID, Muscle_Group_MuscleID) Values
((select ExerciseID from Exercise where ExerciseName = 'Jump Squats'), (select MuscleID from Muscle_Group where MuscleName = 'Lower Body')),
((select ExerciseID from Exercise where ExerciseName = 'Pistol Squats'), (select MuscleID from Muscle_Group where MuscleName = 'Lower Body')),
((select ExerciseID from Exercise where ExerciseName = 'Calf Raises'), (select MuscleID from Muscle_Group where MuscleName = 'Lower Body')),
((select ExerciseID from Exercise where ExerciseName = 'Squats'), (select MuscleID from Muscle_Group where MuscleName = 'Lower Body')),
((select ExerciseID from Exercise where ExerciseName = 'Single-Leg Calf Raises'), (select MuscleID from Muscle_Group where MuscleName = 'Lower Body')),
((select ExerciseID from Exercise where ExerciseName = 'Single-Leg Calf Jumps'), (select MuscleID from Muscle_Group where MuscleName = 'Lower Body')),
((select ExerciseID from Exercise where ExerciseName = 'Glute Bridges'), (select MuscleID from Muscle_Group where MuscleName = 'Lower Body')),
((select ExerciseID from Exercise where ExerciseName = 'Single-Leg Glute Bridges'), (select MuscleID from Muscle_Group where MuscleName = 'Lower Body')),
((select ExerciseID from Exercise where ExerciseName = 'Single-Leg Glute Bridge with hold'), (select MuscleID from Muscle_Group where MuscleName = 'Lower Body')),

((select ExerciseID from Exercise where ExerciseName = 'Russian Twist'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Crunches'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Bicycles'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Flutter Kicks'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Leg Pull-In Knee-ups'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Inchworms'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Lying Leg Raises'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Mountain Climbers'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Plank Jacks'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Toe Touches'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Shoulder Tap Plank'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Elbow Plank'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Sit-ups'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'V-ups'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Side planks'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),
((select ExerciseID from Exercise where ExerciseName = 'Side star planks'), (select MuscleID from Muscle_Group where MuscleName = 'Core')),

((select ExerciseID from Exercise where ExerciseName = 'Modified Push-ups'), (select MuscleID from Muscle_Group where MuscleName = 'Upper Body')),
((select ExerciseID from Exercise where ExerciseName = 'Push-ups'), (select MuscleID from Muscle_Group where MuscleName = 'Upper Body')),
((select ExerciseID from Exercise where ExerciseName = 'Decline Push-ups'), (select MuscleID from Muscle_Group where MuscleName = 'Upper Body')),
((select ExerciseID from Exercise where ExerciseName = 'Tricep Dips'), (select MuscleID from Muscle_Group where MuscleName = 'Upper Body')),
((select ExerciseID from Exercise where ExerciseName = 'Negative pull-up'), (select MuscleID from Muscle_Group where MuscleName = 'Upper Body')),
((select ExerciseID from Exercise where ExerciseName = 'Pull-ups with resistance band'), (select MuscleID from Muscle_Group where MuscleName = 'Upper Body')),
((select ExerciseID from Exercise where ExerciseName = 'Reverse Fly'), (select MuscleID from Muscle_Group where MuscleName = 'Upper Body')),
((select ExerciseID from Exercise where ExerciseName = 'Pull-ups'), (select MuscleID from Muscle_Group where MuscleName = 'Upper Body')),
((select ExerciseID from Exercise where ExerciseName = 'Push-up Shoulder Taps'), (select MuscleID from Muscle_Group where MuscleName = 'Upper Body')),
((select ExerciseID from Exercise where ExerciseName = 'Modified Diamond Push-ups'), (select MuscleID from Muscle_Group where MuscleName = 'Upper Body'));

insert into Exercise_Image(Exercise_ExerciseID) values
((select ExerciseID from Exercise where ExerciseName = 'Jump Squats')),
((select ExerciseID from Exercise where ExerciseName = 'Pistol Squats')),
((select ExerciseID from Exercise where ExerciseName = 'Calf Raises')),
((select ExerciseID from Exercise where ExerciseName = 'Squats')),
((select ExerciseID from Exercise where ExerciseName = 'Single-Leg Calf Raises')),
((select ExerciseID from Exercise where ExerciseName = 'Single-Leg Calf Jumps')),
((select ExerciseID from Exercise where ExerciseName = 'Glute Bridges')),
((select ExerciseID from Exercise where ExerciseName = 'Single-Leg Glute Bridges')),
((select ExerciseID from Exercise where ExerciseName = 'Single-Leg Glute Bridge with hold')),

((select ExerciseID from Exercise where ExerciseName = 'Russian Twist')),
((select ExerciseID from Exercise where ExerciseName = 'Crunches')),
((select ExerciseID from Exercise where ExerciseName = 'Bicycles')),
((select ExerciseID from Exercise where ExerciseName = 'Flutter Kicks')),
((select ExerciseID from Exercise where ExerciseName = 'Leg Pull-In Knee-ups')),
((select ExerciseID from Exercise where ExerciseName = 'Inchworms')),
((select ExerciseID from Exercise where ExerciseName = 'Lying Leg Raises')),
((select ExerciseID from Exercise where ExerciseName = 'Mountain Climbers')),
((select ExerciseID from Exercise where ExerciseName = 'Plank Jacks')),
((select ExerciseID from Exercise where ExerciseName = 'Toe Touches')),
((select ExerciseID from Exercise where ExerciseName = 'Shoulder Tap Plank')),
((select ExerciseID from Exercise where ExerciseName = 'Elbow Plank')),
((select ExerciseID from Exercise where ExerciseName = 'Sit-ups')),
((select ExerciseID from Exercise where ExerciseName = 'V-ups')),
((select ExerciseID from Exercise where ExerciseName = 'Side planks')),
((select ExerciseID from Exercise where ExerciseName = 'Side star planks')),

((select ExerciseID from Exercise where ExerciseName = 'Modified Push-ups')),
((select ExerciseID from Exercise where ExerciseName = 'Push-ups')),
((select ExerciseID from Exercise where ExerciseName = 'Decline Push-ups')),
((select ExerciseID from Exercise where ExerciseName = 'Tricep Dips')),
((select ExerciseID from Exercise where ExerciseName = 'Negative pull-up')),
((select ExerciseID from Exercise where ExerciseName = 'Pull-ups with resistance band')),
((select ExerciseID from Exercise where ExerciseName = 'Reverse Fly')),
((select ExerciseID from Exercise where ExerciseName = 'Pull-ups')),
((select ExerciseID from Exercise where ExerciseName = 'Push-up Shoulder Taps')),
((select ExerciseID from Exercise where ExerciseName = 'Modified Diamond Push-ups'));
