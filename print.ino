void info(double a, double b, int fbf, int fbb, int lrr, int lrl){

    // Serial.print("lrr:");
    // Serial.print(lrr);
    // Serial.print("\tlrl:");
    // Serial.print(lrl);
    // Serial.print("\tfbf:");
    // Serial.print(fbf);
    // Serial.print("\tfbb:");
    // Serial.print(fbb);
    // Serial.print("\tF:");
    // Serial.print(fbf);
    // Serial.print("\tB:");
    // Serial.print(fbb);
    // Serial.print("\tCR:");
    // Serial.print(+ cr);
    // Serial.print("\tCL:");
    // Serial.print(cl);
    Serial.print("\n"); 

    if(a==0 && b==0){
    
    }else if(a>max1){ //Front
        if(b>max2){
            Serial.print("mlf: ");
            Serial.print(fbf);
            Serial.print("\tmrf: ");
            Serial.print(255-lrr);
        }else if(b<min2){
            Serial.print("mlf: ");
            Serial.print(255-lrl);
            Serial.print("\tmrf: ");
            Serial.print(fbf);
        }else{
            Serial.print("f: ");
            Serial.print(fbf);
        }
    }else if(a<min1){ //Back
        if(b>max2){
            Serial.print("mlb: ");
            Serial.print(fbb);
            Serial.print("\tmrb: ");
            Serial.print(255-lrr);
        }else if(b<min2){
            Serial.print("mlb: ");
            Serial.print(255-lrl);
            Serial.print("\tmrb: ");
            Serial.print(fbb);
        }else{
            Serial.print("b: ");
            Serial.print(fbb);
        }
    }else if(b<min2){ //Left
        Serial.print("mlb: ");
        Serial.print(lrl);
        Serial.print("\tmrf: ");
        Serial.print(lrl);
    }else if(b>max2){ //Right
        Serial.print("mlf: ");
        Serial.print(lrr);
        Serial.print("\tmrb: ");
        Serial.print(lrr);
    }else{      

    }
}
