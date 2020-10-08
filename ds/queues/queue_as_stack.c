insert(10){
    push(s0, k);
}

delete2(){
    if(s0 and s1 empty){
        not possible
    }

    if(s1 is not empty){
        pop(s1)
    }
    else{
        while(s0 is not empty){
            pop(s0, n)
            push(s1, n)
        }
        pop(s1, n)
    }
}

// write case for if s1 is filled up and s0 is completely empty