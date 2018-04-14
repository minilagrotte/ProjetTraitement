#include "MyImage.h"


MyImage::MyImage(const wxString& fileName)
: wxImage(fileName)
{
}

MyImage::MyImage(wxImage image)
: wxImage(image)
{
}


MyImage::MyImage(int largeur, int hauteur)
: wxImage(largeur, hauteur)
{
}

MyImage::MyImage()
{
}

MyImage::~MyImage()
{}

void MyImage::negative(){
    unsigned char* data = this->GetData();
    int i = 0;
    const int boucle = this->GetHeight() * this->GetWidth() * 3;
    while(i < boucle){
        data[i] = 255 - data[i];
        i++;
    }
}

void MyImage::Desaturate(){
    unsigned char* data = this->GetData();
    int i = 0;
    const int boucle = this->GetHeight() * this->GetWidth() * 3;
    while(i < boucle){
        int l = 0.2126 *data[i] + 0.7152 *data[i] + 0.0722 *data[i];
        data[i] = l;
        data[i+1] = l;
        data[i+2] = l;
        i += 3;
    }
}

void MyImage::Threshold(int seuil){

    Desaturate();

    unsigned char* data = this->GetData();
    int i = 0;
    const int boucle = this->GetHeight() * this->GetWidth() * 3;
    while(i < boucle){

        int l = 0;
        if(data[i] >= seuil){
            l = 255;
        }
        data[i] = l;
        data[i+1] = l;
        data[i+2] = l;
        i += 3;
    }
}

void MyImage::Mirroir(bool horiz){
    int widht = this->GetWidth();
    int height = this->GetHeight();
    unsigned char* data = this->GetData();
    int i;
    int j;

    if(!horiz){
        i = 0;
        j = widht;
        for(int y = 0; y < height; y++){
            while(i <= j){

                unsigned char r1,r2,g1,g2,b1,b2;

                GetPixel(data,widht,height,i,y,r1,g1,b1);
                GetPixel(data,widht,height,j,y,r2,g2,b2);

                SetPixel(data,widht,height,j,y,r1,g1,b1);
                SetPixel(data,widht,height,i,y,r2,g2,b2);
                i++;
                j--;
            }
            i = 0;
            j = widht;
        }
    } else {
        i = 0;
        j = height;
        for(int x = 0; x < widht; x++){
            while(i <= j){

                unsigned char r1,r2,g1,g2,b1,b2;

                GetPixel(data,widht,height,x,i,r1,g1,b1);
                GetPixel(data,widht,height,x,j,r2,g2,b2);

                SetPixel(data,widht,height,x,j,r1,g1,b1);
                SetPixel(data,widht,height,x,i,r2,g2,b2);
                i++;
                j--;
            }
            i = 0;
            j = height;
        }
    }

}

MyImage* MyImage::Rotation90(){

    int height = this->GetHeight();
    int width = this->GetWidth();

    MyImage* img = new MyImage(height,width);

    unsigned char* data = this->GetData();
    unsigned char* dataNewImg = img->GetData();

    for(int i = 0;i < width;i++){
        for(int j = 0;j < height;j++){

            unsigned char r1,r2,g1,g2,b1,b2;
            this->GetPixel(data,width,height,i,j,r1,g1,b1);
            img->SetPixel(dataNewImg,height,width,height-j,i,r1,g1,b1);

        }
    }

    return img;
    /*i = 0;
    j = widht;
    for(int y = 0; y < height; y++){
        while(i <= j){

            unsigned char r1,r2,g1,g2,b1,b2;

            //GetPixel(data,widht,height,i,y,r1,g1,b1);
            //GetPixel(data,widht,height,j,y,r2,g2,b2);

            //SetPixel(data,widht,height,j,y,r1,g1,b1);
            //SetPixel(data,widht,height,i,y,r2,g2,b2);
            i++;
            j--;
        }
        i = 0;
        j = widht;
    }*/
}

void MyImage::posterize(){
    unsigned char* data = this->GetData();
    int i = 0;
    const int boucle = this->GetHeight() * this->GetWidth() * 3;

    int nb_bit = 1; // nb bits de codage

    while(i < boucle){
        //data[i] = round((float)data[i]/255)*255;



        bool b = (data[i] >> (8-(nb_bit+1)))%2;
        data[i] = (data[i] >> (8-nb_bit))<<(8-nb_bit) + b? 255/nb_bit-1 : 0;

        /*bool b = data[i]%2;
        data[i] = (data[i]-1 >> (8-nb_bit))<<(8-nb_bit) *2 + b? 1 : 2;
        */
        i ++;
    }}

int MyImage::histogramme(){
    unsigned char* data = GetData();
    /*int compt[256][256][256] = {0};
    unsigned char r;
    unsigned char g;
    unsigned char b;

    int i = 0;
    const int boucle = this->GetHeight() * this->GetWidth() * 3;
    while(i < boucle){
        r = data[i];
        i++;
        g = data[i];
        i++;
        b = data[i];
        i++;

        compt[r][g][b] += 1;
    }

    int nbCouleur = 0;

    for(int i =0; i < 256; i++){
        for(int j =0; j < 256; j++){
            for(int k =0; k < 256; k++){
                if(compt[i][j][k] > 0)
                    nbCouleur++;
            }
        }
    }*/

    int* compt = (int*) malloc(16777216 * sizeof(int));
    for(int i = 0; i < 16777216; i++){ //init à 0
        compt[i] = 0;
    }
    unsigned char r;
    unsigned char g;
    unsigned char b;
    int indice;
    const int boucle = this->GetHeight() * this->GetWidth() * 3;
    int i = 0;

    while(i < boucle){
        r = data[i];
        i++;
        g = data[i];
        i++;
        b = data[i];
        i++;

        indice = (r << 16) + (g << 8) + b;

        compt[indice] += 1;
    }

    int nbCouleur = 0;
    for(int i = 0; i < 16777216; i++){ //init à 0
        if(compt[i] > 0){
            nbCouleur++;
        }
    }

    return nbCouleur;
}

void MyImage::Trame(){
    this->Desaturate();

    int placePix = 0;
    int largeur = this->GetWidth();
    int hauteur = this->GetHeight();
    int taille = this->GetHeight() * this->GetWidth() * 3 ;
    unsigned char* data = this->GetData();


    for(int i =0;i<largeur;i=i+4){
        for(int j =0;j<hauteur;j=j+4){


            int seuil = recupSeuil(i,j);
            if(seuil>224){
                for(int h = i ; h<(i+4) ; h++){
                    for(int k = j ;k<(j+4) ; k++){

                        placePix = ((k*largeur)+h)*3;

                        for(int t=0;t<3;t++){
                            if(placePix+t < taille){
                               data[placePix+t] = 255;
                            }
                        }
                    }
                }
            }else if(seuil<=224 && 193<seuil){
                for(int h = i;h<=i+3;h++){
                    for(int k = j;k<=j+3;k++){
                        placePix = ((k*largeur)+h)*3;
                        if(h==i+1 && k==j+1){
                            for(int t=0;t<3;t++){
                                if(placePix+t < taille){
                                    data[placePix+t] = 0;
                                }
                            }
                        }else{
                            for(int t=0;t<3;t++){
                                if(placePix+t < taille){
                                    data[placePix+t] = 255;
                                }
                            }
                        }

                    }
                }
            }else if(seuil<=193 && 162<seuil){
                for(int h = i;h<=i+3;h++){
                    for(int k = j;k<=j+3;k++){
                        placePix = ((k*largeur)+h)*3;
                        if((h==i+1 && k==j+1) ||(h==i+2 && k==j+2) ){
                            for(int t=0;t<3;t++){
                                if(placePix+t < taille){
                                    data[placePix+t] = 0;
                                }
                            }
                        }else{
                            for(int t=0;t<3;t++){
                                if(placePix+t < taille){
                                    data[placePix+t] = 255;
                                }
                            }
                        }

                    }
                }
            }else if(seuil<=162 && 131<seuil){
                for(int h = i;h<=i+3;h++){
                    for(int k = j;k<=j+3;k++){
                        placePix = ((k*largeur)+h)*3;
                        if((h==i+1 && k==j+1) ||(h==i+2 && k==j+2) ||(h==i+1 && k==j+2) ){
                            for(int t=0;t<3;t++){
                                if(placePix+t < taille){
                                    data[placePix+t] = 0;
                                }
                            }
                        }else{
                            for(int t=0;t<3;t++){
                                if(placePix+t < taille){
                                    data[placePix+t] = 255;
                                }
                            }
                        }

                    }
                }
            }else if(seuil<=131 && 100<seuil){
                for(int h = i;h<=i+3;h++){
                    for(int k = j;k<=j+3;k++){
                        placePix = ((k*largeur)+h)*3;
                        if((j<k && k<j+3) && (i<h && h<i+3) ){
                            for(int t=0;t<3;t++){
                                if(placePix+t < taille){
                                    data[placePix+t] = 0;
                                }
                            }
                        }else{
                            for(int t=0;t<3;t++){
                                if(placePix+t < taille){
                                    data[placePix+t] = 255;
                                }
                            }
                        }

                    }
                }
            }else if(seuil<=100 && 69<seuil){
                for(int h = i;h<=i+3;h++){
                    for(int k = j;k<=j+3;k++){
                        placePix = ((k*largeur)+h)*3;
                        if(((h==i && k==j+1)||(h==i+1 && k==j+3)||(h==i+2 &&k==j)||(h==i+3 && k==j+2)) || ((j<k && k<j+3) && (i<h && h<i+3) ) ){
                            for(int t=0;t<3;t++){
                                if(placePix+t < taille){
                                    data[placePix+t] = 0;
                                }
                            }
                        }else{
                            for(int t=0;t<3;t++){
                                if(placePix+t < taille){
                                    data[placePix+t] = 255;
                                }
                            }
                        }
                    }
                }
            }else if( seuil<=69 && 38<seuil){
                for(int h = i;h<=i+3;h++){
                    for(int k = j;k<=j+3;k++){
                        placePix = ((k*largeur)+h)*3;
                        if((h==i&&( k==j|| k==j+3)) || (h==i+3 && ( k==j|| k==j+3))){
                            for(int t=0;t<3;t++){

                                if(placePix+t < taille){
                                    data[placePix+t] = 255;
                                }
                            }
                        }else{
                            for(int t=0;t<3;t++){
                                if(placePix+t < taille){
                                    data[placePix+t] = 0;
                                }
                            }
                        }
                    }
                }
            }else{
                for(int h = i;h<=i+3;h++){
                    for(int k = j;k<=j+3;k++){
                            placePix = ((k*largeur)+h)*3;
                        for(int t=0;t<3;t++){
                                if(placePix+t < taille){
                                    data[placePix+t] = 0;
                                }
                        }
                    }
                }
            }
        }
    }
}


int MyImage::recupSeuil(int xCase,int yCase){
    unsigned char* data = this->GetData();
    int placePix = 0;
    int seuil = 0;
    int nbPix = 0;
    int taille = this->GetHeight() * this->GetWidth() * 3 ;
    int largeur = this->GetWidth();
    for(int x = xCase; x<=xCase+3;x++){
        for(int y = yCase;y<=yCase+3;y++){
            placePix = (y*largeur+x)*3;
            if(placePix<taille){
               seuil += data[placePix];
               nbPix++;
            }

        }
    }
    seuil = (int)(seuil/nbPix);
    return seuil;
}


void MyImage::GetPixel(unsigned char* data, int width, int height, int x, int y, unsigned char& r,unsigned char& g,unsigned char& b){
    int pos = (y * width + x)*3;
    r = data[pos];
    g = data[pos+1];
    b = data[pos+2];
}

void MyImage::SetPixel(unsigned char* data, int width, int height, int x, int y, unsigned char& r,unsigned char& g,unsigned char& b){
    int pos = (y * width + x)*3;
    data[pos] = r;
    data[pos+1] = g;
    data[pos+2] = b;
}
