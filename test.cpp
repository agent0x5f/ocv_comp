#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 1. Abrir la cámara (ID 0 es la predeterminada)
    VideoCapture cap(0);

    if (!cap.isOpened()) {
        cout << "Error: No se pudo abrir la cámara." << endl;
        return -1;
    }

    Mat frame, gray, blur, edges;
    cout << "Presiona cualquier tecla para salir..." << endl;

    while (true) {
        // 2. Capturar el frame actual
        cap >> frame;
        if (frame.empty()) break;

        // 3. Convertir a escala de grises
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // 4. Aplicar desenfoque Gaussiano para reducir ruido
        // El kernel (5, 5) ayuda a que los bordes sean más limpios
        GaussianBlur(gray, blur, Size(5, 5), 0);

        // 5. Algoritmo de Canny
        // Parámetros: imagen_entrada, imagen_salida, umbral_bajo, umbral_alto
        Canny(blur, edges, 50, 150);

        // 6. Mostrar el resultado en una ventana
        imshow("Deteccion de Bordes (C++ / Canny)", edges);

        // Esperar 30ms. Si se presiona una tecla, salir.
        if (waitKey(30) >= 0) break;
    }

    // Al salir del scope, cap se libera automáticamente en C++
    destroyAllWindows();
    return 0;
}
