class ball{
    protected:
        float *weight;
        float *height;
    public:
        ball();
        virtual void show();
        void set_WH(float,float);
        float sphere();
        ~ball();
};

class basketball:public ball
{
    public:
        //basketball();
        //void set_WH(float,float);
        //float sphere();
        //~basketball();
        float volume();
        void show();
};



