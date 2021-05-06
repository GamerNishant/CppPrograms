
class vector {
    int cs;
    int ms;
    int *arr;

    public:
    vector(){
        cs= 0;
        ms =1;
        arr = new int[ms];
    }

    void push_back (int d)
    {
        if(cs ==ms)
        {
            //Array if full
            int *oldarr = arr;
            arr = new int [2*ms];
            ms = 2*ms;
            for(int i = 0 ; i< cs; i++)
            {
                arr[i] = oldarr[i];
            }

            arr[cs] = d;
            cs++;
        }
    }

    // //similarly other function
    // like erase, pop_back, front , 
    // end, print, and clear and reserve and
    // resize and size and capacity and max_size
    // empty functions that boolean true and false..
};
