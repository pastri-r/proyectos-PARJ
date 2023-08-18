using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace RisXpert
{
    public partial class RisXpert : Form
    {
        private List<string> datosCapturados = new List<string>();

        public RisXpert()
        {
            InitializeComponent();
        }

        private void dataGridView4_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            foreach (DataGridViewRow row in DGV3.Rows)
            {
                if (row.IsNewRow) continue; // Ignorar la fila de nueva entrada

                foreach (DataGridViewCell cell in row.Cells)
                {
                    if (int.TryParse(cell.Value.ToString(), out int value))
                    {
                        Color cellColor = Color.White; // Color predeterminado si el valor no es válido

                        // Clasificar valores en colores
                        switch (value)
                        {
                            case 1:
                                cellColor = Color.LightGreen;
                                break;
                            case 2:
                                cellColor = Color.Green;
                                break;
                            case 3:
                                cellColor = Color.Yellow;
                                break;
                            case 4:
                                cellColor = Color.Red;
                                break;
                            case 5:
                                cellColor = Color.DarkRed;
                                break;
                        }

                        // Aplicar el color a la celda
                        cell.Style.BackColor = cellColor;
                    }
                    else
                    {
                        MessageBox.Show($"Valor inválido en la fila {row.Index + 1}. Debe ser un número.");
                    }
                }
            }

            MessageBox.Show("Clasificación de colores de filas completada.");
        }

        private void button1_Click(object sender, EventArgs e)
        {
            String Nombre = TBNOMBRE.Text;
            String Riesgo = TBRIESGO.Text;
            String Daño = TBDAÑO.Text;


            int rowIndex = DGV1.Rows.Add();

            DGV1.Rows[rowIndex].Cells["ID"].Value = rowIndex + 001;
            DGV1.Rows[rowIndex].Cells["Nombre"].Value = Nombre;
            DGV1.Rows[rowIndex].Cells["Riesgo"].Value = Riesgo;
            DGV1.Rows[rowIndex].Cells["Daño"].Value = Daño;


            TBNOMBRE.Text = "";
            TBRIESGO.Text = "";
            TBDAÑO.Text = "";

        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            datosCapturados.Clear(); // Limpiar datos previos

            foreach (DataGridViewRow row in DGV1.Rows)
            {
                string dato = row.Cells[0].Value?.ToString(); // Obtener dato de la primera celda
                if (!string.IsNullOrEmpty(dato))
                {
                    datosCapturados.Add(dato); // Agregar dato a la lista
                }
            }

            MessageBox.Show("Datos guardados en TabPage1.");
        }

        private void button10_Click(object sender, EventArgs e)
        {
            // Obtener el DataGridView de TabPage1 (DGV1)
            DataGridView DGV1 = tabPage1.Controls.Find("DGV1", true)[0] as DataGridView;

            // Obtener el DataGridView de TabPage2 (DGV2)
            DataGridView DGV2 = tabPage2.Controls.Find("DGV2", true)[0] as DataGridView;

            // Limpiar DGV2 antes de transferir datos
            DGV2.Rows.Clear();

            // Obtener el DataGridView6 en tabPage4 (DGV6)
            DataGridView dgv6 = tabPage4.Controls.Find("DGV6", true)[0] as DataGridView;

            // Limpiar DGV6 antes de transferir datos
            DGV6.Rows.Clear();

            // Transferir datos desde DGV1 a DGV2
            foreach (DataGridViewRow row in DGV1.Rows)
            {
                if (!row.IsNewRow)
                {
                    object[] rowData = new object[row.Cells.Count];
                    for (int i = 0; i < row.Cells.Count; i++)
                    {
                        rowData[i] = row.Cells[i].Value;
                    }
                    DGV2.Rows.Add(rowData);
                }
            }

            // Transferir las columnas de ID y NOMBRE de DGV1 a DGV6
            foreach (DataGridViewRow row in DGV1.Rows)
            {
                object[] rowData = new object[2]; // Columnas de ID y NOMBRE
                rowData[0] = row.Cells["ID"].Value;
                rowData[1] = row.Cells["NOMBRE"].Value;
                DGV6.Rows.Add(rowData);
            }

            MessageBox.Show("Datos transferidos ");
        }
        private void FormPrincipal_Load(object sender, EventArgs e)
        {
            // Configurar validación de celdas en el DataGridView3
            DGV3.CellValidating += DGV3_CellValidating;
            // Configurar el evento Click del botón para realizar la transferencia
            button4.Click += button4_Click;
            // Configurar el evento Click del botón para realizar los cálculos
            button5.Click += button5_Click;
            // Configurar el evento Click del botón para realizar las operaciones
            button7.Click += button7_Click;
            // Configurar el evento Click del botón para crear la clasificación
            button9.Click += button9_Click;

            // Configurar el evento CellEndEdit del DataGridView6
            DataGridView DGV6 = tabPage1.Controls.Find("DGV6", true)[0] as DataGridView;
            DGV6.CellEndEdit += DGV6_CellEndEdit;
        }
        private void DGV3_CellValidating(object sender, DataGridViewCellValidatingEventArgs e)
        {
            if (e.RowIndex >= 0 && e.ColumnIndex >= 0)
            {
                if (e.ColumnIndex >= 1 && e.ColumnIndex <= 5) // Limitar a las celdas 1 a 5
                {
                    string nuevoValor = e.FormattedValue.ToString();
                    int valorParseado;

                    if (!int.TryParse(nuevoValor, out valorParseado) || valorParseado < 1 || valorParseado > 5)
                    {
                        DGV3.Rows[e.RowIndex].Cells[e.ColumnIndex].ErrorText = "El valor debe ser un número entre 1 y 5.";
                        e.Cancel = true;
                    }
                    else
                    {
                        DGV3.Rows[e.RowIndex].Cells[e.ColumnIndex].ErrorText = "";
                    }
                }
            }
        }
        private void button4_Click(object sender, EventArgs e)
        {
            TransferirDatos();
        }
        private void TransferirDatos()
        {
            // Obtener el DataGridView3 en TabPage2 (DGV3)
            DataGridView dgv3 = tabPage2.Controls.Find("DGV3", true)[0] as DataGridView;

            // Obtener el DataGridView4 en TabPage3 (DGV4)
            DataGridView dgv4 = tabPage3.Controls.Find("DGV4", true)[0] as DataGridView;

            // Limpiar DGV4 antes de transferir datos
            DGV4.Rows.Clear();

            // Transferir datos numéricos y colores desde DGV3 a DGV4
            foreach (DataGridViewRow row in DGV3.Rows)
            {
                DataGridViewCellCollection cells = row.Cells;

                // Agregar una nueva fila en DGV4
                int index = DGV4.Rows.Add();

                // Transferir valores numéricos y colores de celdas
                DGV4.Rows[index].Cells[0].Value = cells["SUSTITUCION"].Value;
                DGV4.Rows[index].Cells[1].Value = cells["EXTENSION"].Value;
                DGV4.Rows[index].Cells[2].Value = cells["FUNCION"].Value;
                DGV4.Rows[index].Cells[3].Value = cells["PROFUNDIDAD"].Value;
                DGV4.Rows[index].Cells[4].Value = cells["AGRESION"].Value;
                DGV4.Rows[index].Cells[5].Value = cells["VULNERABILIDAD"].Value;

                // Transferir colores de celdas
                for (int i = 0; i < dgv4.Columns.Count; i++)
                {
                    Color cellColor = cells[i].Style.BackColor;
                    DGV4.Rows[index].Cells[i].Style.BackColor = cellColor;
                }
            }

            MessageBox.Show("Datos y colores de celda transferidos a TabPage3.");
        }

        private void button5_Click(object sender, EventArgs e)
        {
            RealizarCalculos();
        }
        private void RealizarCalculos()
        {
            // Obtener el DataGridView4 en TabPage3 (DGV4)
            DataGridView DGV4 = tabPage3.Controls.Find("DGV4", true)[0] as DataGridView;

            // Obtener el DataGridView5 en TabPage3 (DGV5)
            DataGridView DGV5 = tabPage3.Controls.Find("DGV5", true)[0] as DataGridView;

            // Realizar los cálculos y actualizar los valores en DGV5
            for (int rowIndex = 0; rowIndex < DGV5.Rows.Count; rowIndex++)
            {
                DataGridViewRow row = DGV5.Rows[rowIndex];

                double fValue = Convert.ToDouble(DGV4.Rows[rowIndex].Cells["F"].Value);
                double sValue = Convert.ToDouble(DGV4.Rows[rowIndex].Cells["S"].Value);
                row.Cells["IMPORTANCIA_DEL_SUCESO"].Value = fValue * sValue;

                double pValue = Convert.ToDouble(DGV4.Rows[rowIndex].Cells["P"].Value);
                double eValue = Convert.ToDouble(DGV4.Rows[rowIndex].Cells["E"].Value);
                row.Cells["DAÑOS_OCASIONADOS"].Value = pValue * eValue;

                double importanciaDelSuceso = Convert.ToDouble(row.Cells["IMPORTANCIA_DEL_SUCESO"].Value);
                double danosOcasioandos = Convert.ToDouble(row.Cells["DAÑOS_OCASIONADOS"].Value);
                row.Cells["CARACTER_DE_RIESGO"].Value = importanciaDelSuceso + danosOcasioandos;

                double aValue = Convert.ToDouble(DGV4.Rows[rowIndex].Cells["A"].Value);
                double vValue = Convert.ToDouble(DGV4.Rows[rowIndex].Cells["V"].Value);
                row.Cells["PROBABILIDAD_DE_RIESGO"].Value = aValue * vValue;

                double caracterDeRiesgo = Convert.ToDouble(row.Cells["CARACTER_DE_RIESGO"].Value);
                double probabilidadDeRiesgo = Convert.ToDouble(row.Cells["PROBABILIDAD_DE_RIESGO"].Value);
                row.Cells["CUANTIFICACION_DE_RIESGO"].Value = caracterDeRiesgo * probabilidadDeRiesgo;
            }

            MessageBox.Show("Cálculos realizados y actualizados en TabPage3.");
        }

        private void button7_Click(object sender, EventArgs e)
        {
            PlasmarCuantificacion();
        }
        private void PlasmarCuantificacion()
        {
            // Obtener el DataGridView5 en TabPage3 (DGV5)
            DataGridView DGV5 = tabPage3.Controls.Find("DGV5", true)[0] as DataGridView;

            // Obtener el DataGridView6 en la misma tabPage
            DataGridView DGV6 = tabPage4.Controls.Find("DGV6", true)[0] as DataGridView;

            // Plasmar datos de DGV5 en DGV6
            for (int rowIndex = 0; rowIndex < DGV5.Rows.Count; rowIndex++)
            {
                double cuantificacionValue = Convert.ToDouble(DGV5.Rows[rowIndex].Cells["CUANTIFICACION_DE_RIESGO"].Value);
                DGV6.Rows[rowIndex].Cells["VALOR_ER_RIESGO"].Value = cuantificacionValue;
            }

            MessageBox.Show("Cuantificación plasmada en DGV6.");
        }

        private void button8_Click(object sender, EventArgs e)
        {

        }
        private void DGV6_CellEndEdit(object sender, DataGridViewCellEventArgs e)
        {
            // Verificar si la celda editada es de la columna IDENTIF
            if (e.ColumnIndex == DGV6.Columns["IDENTIF"].Index)
            {
                // Verificar que el valor en la celda sea un número entero
                if (int.TryParse(DGV6.Rows[e.RowIndex].Cells["IDENTIF"].Value?.ToString(), out int identifValue))
                {
                    // Incrementar el valor en 1 y actualizar la celda
                    DGV6.Rows[e.RowIndex].Cells["IDENTIF"].Value = (identifValue + 1).ToString();
                }
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            CrearClasificacion();
        }
        private void CrearClasificacion()
        {
            // Obtener el DataGridView6 en TabPage3 (DGV6)
            DataGridView DGV6 = tabPage4.Controls.Find("DGV6", true)[0] as DataGridView;

            // Crear la clasificación en función de los valores de VALOR_ER_RIESGO
            foreach (DataGridViewRow row in DGV6.Rows)
            {
                if (double.TryParse(row.Cells["VALOR_ER_RIESGO"].Value?.ToString(), out double valorER))
                {
                    string clasificacion = CalcularClasificacion(valorER);
                    row.Cells["CLASE_DE_RIESGO"].Value = clasificacion;
                }
            }

            MessageBox.Show("Clasificación creada en DGV6.");
        }

        private string CalcularClasificacion(double valorER)
        {
            if (valorER >= 2 && valorER <= 250)
            {
                return "Muy pequeño";
            }
            else if (valorER >= 251 && valorER <= 500)
            {
                return "Pequeño";
            }
            else if (valorER >= 501 && valorER <= 750)
            {
                return "Normal";
            }
            else if (valorER >= 751 && valorER <= 1000)
            {
                return "Grande";
            }
            else if (valorER >= 1001 && valorER <= 1250)
            {
                return "Elevado";
            }
            else
            {
                return "Sin clasificación";
            }
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
        }
    }

}