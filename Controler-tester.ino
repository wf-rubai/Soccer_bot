double c2 = 3;
double c4 = 5;

int min1 = 1420;
int max1 = 1510;

int max2 = 1490;
int min2 = 1400;

//Right motor driver pins
int R_EN_right = 2;
int L_EN_right = 4;
int R_PWM_right = 9;  //PWM pin
int L_PWM_right = 6;  //PWM pin

//Left motor driver pins
int R_EN_left = 7;
int L_EN_left = 8;
int R_PWM_left = 10;  //PWM pin
int L_PWM_left = 11;  //PWM pin

void setup() {
    Serial.begin(9600);
    pinMode(c4, INPUT);
    pinMode(c2, INPUT);
    pinMode(R_EN_left, OUTPUT);
    pinMode(L_EN_left, OUTPUT);
    pinMode(R_EN_right, OUTPUT);
    pinMode(L_EN_right, OUTPUT);
    pinMode(R_PWM_left, OUTPUT);
    pinMode(L_PWM_left, OUTPUT);
    pinMode(R_PWM_right, OUTPUT);
    pinMode(L_PWM_right, OUTPUT);
}

void loop() {

    digitalWrite(R_EN_right, HIGH);
    digitalWrite(L_EN_right, HIGH);
    digitalWrite(R_EN_left, HIGH);
    digitalWrite(L_EN_left, HIGH);  

    double a = pulseIn(c2, HIGH);
    double b = pulseIn(c4, HIGH);  

    int fbf = map(a, 1995, max1, 255, 0);
    int fbb = map(a, 985, min1, 255, 0);    

    int lrr = map(b, 1950, max2, 255, 0);
    int lrl = map(b, 980, min2, 255, 0);    

     info(a, b, fbf, fbb, lrr, lrl);  

    if(a==0 && b==0){
        run(0, 0, 0, 0);
    }else if(a>max1){
        if(b>max2){
            lrr = map(b, 1950, max2, fbf, 0);
            run( fbf - lrr, 0, fbf, 0);       // front right
        }else if(b<min2){
            lrl = map(b, 980, min2, fbf, 0);
            run( fbf, 0, fbf - lrl, 0);       // front left
        }else{
            run( fbf, 0, fbf, 0);             // front
        }
    }else if(a<min1){
        if(b>max2){
            lrr = map(b, 1950, max2, fbb, 0);
            run(0, lrr - fbb, 0, fbb);        // back right
        }else if(b<min2){
            lrl = map(b, 980, max2, fbb, 0);
            run(0, fbb, 0, fbb - lrl);        // back left
        }else{
            run(0, fbb, 0, fbb);              // back
        }
    }else if(b<min2){
        run(lrl, 0, 0, lrl);                  // left
    }else if(b>max1){
        run(0, lrr, lrr, 0);                  // right
    }else{
        run(0, 0, 0, 0);
    }
}
