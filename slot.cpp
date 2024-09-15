std::string slot_random_item(){
    int x = 1+rand()%100;
    //🍇🍒🍊🍌🍓🍐😔
    if(1 <= x && x <= 40){
        return "😞"; //40%
    }else if(41 <= x && x <= 55){
        return "🍒"; // 15%
    }else if(56 <= x && x <= 65){
        return "🍊"; // 10%
    }else if(66 <= x && x <= 75){
        return "🍌"; // 10%
    }else if(76 <= x && x <= 85){
        return "🍓"; // 10%
    }else if(86 <= x && x <= 95){
        return "🍐"; // 10%
    }else{
        return "7️⃣ "; // 5%
    }
}