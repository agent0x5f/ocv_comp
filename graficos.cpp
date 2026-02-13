#include "graficos.h"
#include "algoritmo.h"
#include <wx/filedlg.h>
#include <wx/log.h>
#include <wx/frame.h>
#include <wx/msgdlg.h>
#include <wx/event.h>

MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "App Separada", wxPoint(50, 50), wxSize(300, 200)) {
    wxPanel* panel = new wxPanel(this, wxID_ANY);
    wxButton* button = new wxButton(panel, wxID_ANY, "Seleccionar Archivo",
                                    wxPoint(50, 60), wxSize(200, 30));

    button->Bind(wxEVT_BUTTON, &MyFrame::OnOpenExplorer, this);
    CreateStatusBar();
}

void MyFrame::OnOpenExplorer(wxCommandEvent& event) {
    // Filtramos para que solo se vean imágenes
    wxFileDialog openFileDialog(this, "Selecciona una imagen", "", "",
                       "Imágenes (*.jpg;*.png;*.bmp)|*.jpg;*.png;*.bmp",
                       wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if (openFileDialog.ShowModal() == wxID_OK) {
        std::string path = openFileDialog.GetPath().ToStdString();

        // 1. Llamamos al algoritmo y guardamos lo que nos devuelve
        std::string nombreParaMostrar = Algoritmo::procesarImagen(path);

        // 2. Creamos la ventana emergente con el nombre
        wxMessageBox("El algoritmo procesó: " + nombreParaMostrar,
                     "Procesamiento Exitoso",
                     wxOK | wxICON_INFORMATION);
    }
}
