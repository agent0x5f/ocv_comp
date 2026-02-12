#include <wx/wx.h>

class CalculatorFrame : public wxFrame {
public:
    CalculatorFrame() : wxFrame(NULL, wxID_ANY, "Calculadora wxWidgets", wxDefaultPosition, wxSize(300, 400)) {
        // 1. Área de texto para el resultado
        display = new wxTextCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_RIGHT);

        // 2. Sizer de cuadrícula para los botones (4 filas, 4 columnas)
        wxGridSizer* grid = new wxGridSizer(4, 4, 5, 5);

        const char* labels[] = {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "C", "0", "=", "+"
        };

        for (const char* label : labels) {
            wxButton* btn = new wxButton(this, wxID_ANY, label);
            grid->Add(btn, 1, wxEXPAND);
            // Conectar el evento de clic de cada botón
            btn->Bind(wxEVT_BUTTON, &CalculatorFrame::OnButtonClicked, this);
        }

        // 3. Diseño principal vertical
        wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
        mainSizer->Add(display, 0, wxEXPAND | wxALL, 10);
        mainSizer->Add(grid, 1, wxEXPAND | wxALL, 10);

        SetSizer(mainSizer);
    }

private:
    wxTextCtrl* display;

    void OnButtonClicked(wxCommandEvent& event) {
        wxString label = ((wxButton*)event.GetEventObject())->GetLabel();

        if (label == "C") {
            display->Clear();
        } else if (label == "=") {
            // Aquí iría la lógica matemática compleja (parser)
            display->AppendText(" = result");
        } else {
            display->AppendText(label);
        }
    }
};

class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        CalculatorFrame* frame = new CalculatorFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
