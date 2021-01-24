#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

/* Exercicio: Como inverter as cores de uma imagem,
 * melhor, como inverter as cores de uma imagem MAS somente em uma area especifica;
 */
int main() {

    Mat img = imread("../img.jpg");
    Mat imgEditada;
    img.copyTo(imgEditada);
    Rect retang(500, 30, 300, 400);

    for(int i = 0; i < imgEditada.rows; i++){
        for(int j= 0; j < imgEditada.cols; j++){
            if(retang.contains(Point(j, i))){ // se o pixel estiver dentro do retangulo
                imgEditada.at<Vec3b>(i, j)[0] = 255 - imgEditada.at<Vec3b>(i, j)[0]; // tranforma o elemento Azul (B) no seu inverso;
                imgEditada.at<Vec3b>(i, j)[1] = 255 - imgEditada.at<Vec3b>(i, j)[1]; // tranforma o elemento Verde (G) no seu inverso;
                imgEditada.at<Vec3b>(i, j)[2] = 255 - imgEditada.at<Vec3b>(i, j)[2]; // tranforma o elemento Vermelho (R) no seu inverso;
                                                                       // no opencv eh utilizado o espaco de cores BGR ao inves de RGB
                }
        }
    }
    circle(imgEditada, Point(100,100), 50, Scalar(0, 255, 0), 7); // desenha um circulo verde na tela no ponto 100,100;
    imshow("Imagem Editada", imgEditada); // mostra a imagem na tela
    imwrite("imgEditada.jpg", imgEditada); // salva em arquivo

    int tecla = waitKey(0); // faz com que o programa espere ate que o usuario aperte uma tecla. waitkey(2000) espera por 2 segundos, waitKey(60000) por um minuto
    return 0;
}

/* Nota do Autor:
 * Um exercicio interessante a partir dessa implementação é tentar desenhar um retangulo em volta da área com cores invertidas.
 * Interessante também (e consideravelmente mais difícil) seria imprimir (imshow) somente a área com cores invertdas. 
 */
