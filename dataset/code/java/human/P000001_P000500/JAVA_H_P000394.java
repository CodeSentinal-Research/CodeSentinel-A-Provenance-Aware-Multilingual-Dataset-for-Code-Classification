import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableColumn;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Vector;
import java.io.File;
import java.net.URL;
import java.text.NumberFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Locale;
import javax.swing.table.TableColumnModel;

public class Products extends JPanel {

    // UI components for the products panel
    private JTable productTable;
    private DefaultTableModel tableModel;
    private JTextField searchField, productCodeField, productNameField, dateField,
            quantityField, costPriceField, sellingPriceField, brandField;
    private JComboBox<String> supplierComboBox;
    private JButton refreshButton, addSupplierButton, addButton, editButton, deleteButton, clearButton;

    // File paths for data storage
    private String dataFilePath = "products.txt";
    private String suppliersFilePath = "suppliersDetails.txt";

    public Products() {
        //  Layout for the Products panel
        setLayout(new BorderLayout());
        // Top panel for search and refresh Button
        JPanel topPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JLabel searchLabel = new JLabel("Search:");
        searchField = new JTextField(20);
        searchField.setPreferredSize(new Dimension(200, searchField.getPreferredSize().height));
        searchField.addActionListener(e -> searchProducts());
        refreshButton = new JButton("Refresh");
        topPanel.add(searchLabel);
        topPanel.add(searchField);
        topPanel.add(refreshButton);

        // Main center panel for layout
        JPanel mainCenterPanel = new JPanel(new GridBagLayout());

        // Panel for the product table
        JPanel productTablePanel = new JPanel(new BorderLayout());

        // Table column names
        String[] columnNames = {"CODE", "PRODUCT", "COST", "PRICE", "BRAND", "QUANTITY", "DATE"};
        tableModel = new DefaultTableModel(columnNames, 0);
        productTable = new JTable(tableModel);
        productTable.setShowGrid(true);
        productTable.setGridColor(Color.BLACK);

        // Set preferred column widths
        TableColumnModel columnModel = productTable.getColumnModel();
        columnModel.getColumn(0).setPreferredWidth(50);
        columnModel.getColumn(1).setPreferredWidth(150);
        columnModel.getColumn(2).setPreferredWidth(80);
        columnModel.getColumn(3).setPreferredWidth(80);
        columnModel.getColumn(4).setPreferredWidth(100);
        columnModel.getColumn(5).setPreferredWidth(80);
        columnModel.getColumn(6).setPreferredWidth(100);

        JScrollPane tableScrollPane = new JScrollPane(productTable);
        tableScrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);
        tableScrollPane.setPreferredSize(new Dimension(800, 200));
        tableScrollPane.setBorder(BorderFactory.createLineBorder(Color.BLACK));
        productTablePanel.add(tableScrollPane, BorderLayout.CENTER);
        // Right panel for product details and operations
        JPanel rightPanel = new JPanel();
        rightPanel.setLayout(new GridBagLayout());
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(5, 5, 5, 5);
        gbc.anchor = GridBagConstraints.WEST;

        // Supplier section
        gbc.gridx = 0;
        gbc.gridy = 0;
        JLabel supplierLabel = new JLabel("Enter Product Details");
        rightPanel.add(supplierLabel, gbc);

        gbc.gridx = 1;
        gbc.gridy = 0;
        gbc.gridwidth = 2;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        supplierComboBox = new JComboBox<>();
        loadSuppliers();
        rightPanel.add(supplierComboBox, gbc);

        gbc.gridx = 0;
        gbc.gridy = 1;
        gbc.gridwidth = 2;
        addSupplierButton = new JButton("Click to add a New Supplier");
        rightPanel.add(addSupplierButton, gbc);

        // Product Code input
        gbc.gridx = 0;
        gbc.gridy = 2;
        gbc.gridwidth = 1;
        JLabel productCodeLabel = new JLabel("Product Code:");
        rightPanel.add(productCodeLabel, gbc);

        gbc.gridx = 1;
        gbc.gridy = 2;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        productCodeField = new JTextField(10);
        rightPanel.add(productCodeField, gbc);

        // Product Name input
        gbc.gridx = 0;
        gbc.gridy = 3;
        JLabel productNameLabel = new JLabel("Product Name:");
        rightPanel.add(productNameLabel, gbc);

        gbc.gridx = 1;
        gbc.gridy = 3;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        productNameField = new JTextField(10);
        rightPanel.add(productNameField, gbc);

        // Date input
        gbc.gridx = 0;
        gbc.gridy = 4;
        JLabel dateLabel = new JLabel("Date:");
        rightPanel.add(dateLabel, gbc);

        gbc.gridx = 1;
        gbc.gridy = 4;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        dateField = new JTextField(10);
        rightPanel.add(dateField, gbc);

        // Quantity input
        gbc.gridx = 0;
        gbc.gridy = 5;
        JLabel quantityLabel = new JLabel("Quantity:");
        rightPanel.add(quantityLabel, gbc);

        gbc.gridx = 1;
        gbc.gridy = 5;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        quantityField = new JTextField(10);
        rightPanel.add(quantityField, gbc);

        // Cost Price input
        gbc.gridx = 0;
        gbc.gridy = 6;
        JLabel costPriceLabel = new JLabel("Cost Price:");
        rightPanel.add(costPriceLabel, gbc);

        gbc.gridx = 1;
        gbc.gridy = 6;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        costPriceField = new JTextField(10);
        rightPanel.add(costPriceField, gbc);

        // Selling Price input
        gbc.gridx = 0;
        gbc.gridy = 7;
        JLabel sellingPriceLabel = new JLabel("Selling Price:");
        rightPanel.add(sellingPriceLabel, gbc);

        gbc.gridx = 1;
        gbc.gridy = 7;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        sellingPriceField = new JTextField(10);
        rightPanel.add(sellingPriceField, gbc);

        // Brand input
        gbc.gridx = 0;
        gbc.gridy = 8;
        JLabel brandLabel = new JLabel("Brand:");
        rightPanel.add(brandLabel, gbc);

        gbc.gridx = 1;
        gbc.gridy = 8;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        brandField = new JTextField(10);
        rightPanel.add(brandField, gbc);

        // Buttons for operations
        addButton = new JButton("Add");
        editButton = new JButton("Edit");
        deleteButton = new JButton("Delete");
        clearButton = new JButton("CLEAR");

        // Button Panel
        JPanel buttonPanel = new JPanel(new GridLayout(2, 2, 5, 5));
        buttonPanel.add(addButton);
        buttonPanel.add(editButton);
        buttonPanel.add(deleteButton);
        buttonPanel.add(clearButton);

        gbc.gridx = 0;
        gbc.gridy = 9;
        gbc.gridwidth = 2;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        rightPanel.add(buttonPanel, gbc);
        rightPanel.setPreferredSize(new Dimension(450, 0));

        // Panel to combine table and details panel
        JPanel tableAndDetailsPanel = new JPanel(new GridBagLayout());
        gbc = new GridBagConstraints();
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.weightx = 1.0;
        gbc.weighty = 1.0;
        gbc.fill = GridBagConstraints.BOTH;
        tableAndDetailsPanel.add(productTablePanel, gbc);

        gbc.gridx = 1;
        gbc.gridy = 0;
        gbc.weightx = 0.0;
        gbc.weighty = 1.0;
        gbc.fill = GridBagConstraints.VERTICAL;
        gbc.anchor = GridBagConstraints.EAST;
        tableAndDetailsPanel.add(rightPanel, gbc);

        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.weightx = 1.0;
        gbc.weighty = 1.0;
        gbc.fill = GridBagConstraints.BOTH;
        mainCenterPanel.add(tableAndDetailsPanel, gbc);

        // Adding top and main panels to the layout
        add(topPanel, BorderLayout.NORTH);
        add(mainCenterPanel, BorderLayout.CENTER);

        // Checking and creating data file if not exists
        checkAndCreateDataFile();
        // Loading initial product data
        loadProductData();

        // Setting action listeners for buttons
        addButton.addActionListener(e -> addProduct());
        editButton.addActionListener(e -> editProduct());
        deleteButton.addActionListener(e -> deleteProduct());
        clearButton.addActionListener(e -> clearFields());
        refreshButton.addActionListener(e -> refreshTable());

        // Action listener for adding a new supplier
        addSupplierButton.addActionListener(e -> {
            String newSupplierName = JOptionPane.showInputDialog(Products.this, "Enter new supplier name:");
            if (newSupplierName != null && !newSupplierName.trim().isEmpty()) {
                try (BufferedWriter writer = new BufferedWriter(new FileWriter(suppliersFilePath, true))) {
                    // Generate new supplier code
                    String newSupplierCode = "SUP" + (supplierComboBox.getItemCount() + 1);
                    // Write new supplier details
                    String supplierRecord = newSupplierCode + "," + newSupplierName + ",Placeholder City,000-000-0000,0,0";
                    writer.write(supplierRecord);
                    writer.newLine();

                    // Reload suppliers
                    SwingUtilities.invokeLater(() -> {
                        loadSuppliers();
                        supplierComboBox.setSelectedIndex(supplierComboBox.getItemCount() -1);
                    });


                } catch (IOException ex) {
                    ex.printStackTrace();
                    JOptionPane.showMessageDialog(Products.this, "Error adding supplier to file.", "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });
        // List selection listener for the product table
        productTable.getSelectionModel().addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                if (!e.getValueIsAdjusting()) {
                    int selectedRow = productTable.getSelectedRow();
                    if (selectedRow != -1) {
                        // Populate fields with selected row data
                        productCodeField.setText((String) tableModel.getValueAt(selectedRow, 0));
                        productNameField.setText((String) tableModel.getValueAt(selectedRow, 1));
                        costPriceField.setText((String) tableModel.getValueAt(selectedRow, 2));
                        sellingPriceField.setText((String) tableModel.getValueAt(selectedRow, 3));
                        brandField.setText((String) tableModel.getValueAt(selectedRow, 4));
                        quantityField.setText((String) tableModel.getValueAt(selectedRow, 5));
                        dateField.setText((String) tableModel.getValueAt(selectedRow, 6));
                    }
                }
            }
        });
    }
    // Load suppliers from file into the combo box
    private void loadSuppliers() {
        supplierComboBox.removeAllItems();
        try (BufferedReader reader = new BufferedReader(new FileReader(suppliersFilePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length >= 2) {
                    String supplierName = parts[1].trim();
                    supplierComboBox.addItem(supplierName);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error loading suppliers.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
    // Check if the data file exists, and create it if it doesn't
    private void checkAndCreateDataFile() {
        File dataFile = new File(dataFilePath);
        if (!dataFile.exists()) {
            try {
                dataFile.createNewFile();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    // Load product data from file into the table
    private void loadProductData() {
        File dataFile = new File(dataFilePath);
        if (!dataFile.exists()) {
            return;
        }
        try (BufferedReader reader = new BufferedReader(new FileReader(dataFilePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 7) {
                    Vector<String> row = new Vector<>();
                    row.add(parts[0]);
                    row.add(parts[1]);
                    row.add(parts[2]);
                    row.add(parts[3]);
                    row.add(parts[4]);
                    row.add(parts[5]);
                    String dateString = parts[6];
                    LocalDate date = null;
                    DateTimeFormatter formatter1 = DateTimeFormatter.ofPattern("MM/dd/yyyy");
                    DateTimeFormatter formatter2 = DateTimeFormatter.ofPattern("M/d/yyyy");
                    try {
                        date = LocalDate.parse(dateString, formatter1);
                    } catch (java.time.format.DateTimeParseException e) {
                        try {
                            date = LocalDate.parse(dateString, formatter2);
                        } catch(java.time.format.DateTimeParseException ex){
                            ex.printStackTrace();
                            JOptionPane.showMessageDialog(this, "Error parsing date: " + dateString, "Error", JOptionPane.ERROR_MESSAGE);
                            continue;
                        }
                    }
                    row.add(date.format(formatter1));


                    tableModel.addRow(row);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    // Save product data from the table into the file
    private void saveProductData() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(dataFilePath))) {
            for (int i = 0; i < tableModel.getRowCount(); i++) {
                String productCode = (String) tableModel.getValueAt(i, 0);
                String productName = (String) tableModel.getValueAt(i, 1);
                String costPrice = (String) tableModel.getValueAt(i, 2);
                String sellPrice = (String) tableModel.getValueAt(i, 3);
                String brand = (String) tableModel.getValueAt(i, 4);
                String quantity = (String) tableModel.getValueAt(i, 5);
                String date = (String) tableModel.getValueAt(i, 6);

                writer.write(productCode + "," + productName + "," + costPrice + "," + sellPrice + "," + brand + "," + quantity + "," + date);
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error saving data to file.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
    // Add a new product to the table and save it to the file
    private void addProduct() {
        String productCode = productCodeField.getText();
        String productName = productNameField.getText();
        String costPriceStr = costPriceField.getText();
        String sellPriceStr = sellingPriceField.getText();
        String brand = brandField.getText();
        String quantityStr = quantityField.getText();
        // Get the current date in the specified format
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MM/dd/yyyy");
        String date = LocalDate.now().format(formatter);

        if (productCode.isEmpty() || productName.isEmpty() || costPriceStr.isEmpty() || sellPriceStr.isEmpty() || brand.isEmpty() || quantityStr.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Please fill in all fields.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        double costPrice, sellPrice;
        int quantity;
        try {
            costPrice = Double.parseDouble(costPriceStr);
            sellPrice = Double.parseDouble(sellPriceStr);
            quantity = Integer.parseInt(quantityStr);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Invalid cost price, selling price, or quantity format.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        Vector<String> newRow = new Vector<>();
        newRow.add(productCode);
        newRow.add(productName);
        newRow.add(costPriceStr);
        newRow.add(sellPriceStr);
        newRow.add(brand);
        newRow.add(quantityStr);
        newRow.add(date);

        tableModel.addRow(newRow);
        saveProductData();
        clearFields();
    }
    // Edit the selected product in the table and update the file
    private void editProduct() {
        int selectedRow = productTable.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(this, "Please select a product to edit.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        String productCode = productCodeField.getText();
        String productName = productNameField.getText();
        String costPriceStr = costPriceField.getText();
        String sellPriceStr = sellingPriceField.getText();
        String brand = brandField.getText();
        String quantityStr = quantityField.getText();

        // Get the current date in the specified format
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MM/dd/yyyy");
        String date = LocalDate.now().format(formatter);

        if (productCode.isEmpty() || productName.isEmpty() || costPriceStr.isEmpty() || sellPriceStr.isEmpty() || brand.isEmpty() || quantityStr.isEmpty()) {
            JOptionPane.showMessageDialog(this, "Please fill in all fields.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        double costPrice;
        double sellPrice;
        int quantity;
        try {
            costPrice = Double.parseDouble(costPriceStr);
            sellPrice = Double.parseDouble(sellPriceStr);
            quantity = Integer.parseInt(quantityStr);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Invalid cost price, selling price, or quantity format.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        tableModel.setValueAt(productCode, selectedRow, 0);
        tableModel.setValueAt(productName, selectedRow, 1);
        tableModel.setValueAt(costPriceStr, selectedRow, 2);
        tableModel.setValueAt(sellPriceStr, selectedRow, 3);
        tableModel.setValueAt(brand, selectedRow, 4);
        tableModel.setValueAt(quantityStr, selectedRow, 5);
        tableModel.setValueAt(date, selectedRow, 6);

        saveProductData();
        clearFields();
    }
    // Delete the selected product from the table and update the file
    private void deleteProduct() {
        int selectedRow = productTable.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(this, "Please select a product to delete.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        tableModel.removeRow(selectedRow);
        saveProductData();
        clearFields();
    }
    // Clear all input fields
    private void clearFields() {
        productCodeField.setText("");
        productNameField.setText("");
        dateField.setText("");
        quantityField.setText("");
        costPriceField.setText("");
        sellingPriceField.setText("");
        brandField.setText("");
        supplierComboBox.setSelectedIndex(0);

        // Set the date field to the current date
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("MM/dd/yyyy");
        String currentDate = LocalDate.now().format(formatter);
        dateField.setText(currentDate);
    }
    // Refresh the table by reloading the data from the file
    private void refreshTable() {
        tableModel.setRowCount(0);
        loadProductData();
    }
    // Search products in the table based on the search term
    private void searchProducts() {
        String searchTerm = searchField.getText().trim().toLowerCase();
        tableModel.setRowCount(0);
        try (BufferedReader reader = new BufferedReader(new FileReader(dataFilePath))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",");
                if (parts.length == 7) {
                    if (containsSearchTerm(parts, searchTerm)) {
                        Vector<String> row = new Vector<>();
                        row.add(parts[0]);
                        row.add(parts[1]);
                        row.add(parts[2]);
                        row.add(parts[3]);
                        row.add(parts[4]);
                        row.add(parts[5]);
                        row.add(parts[6]);
                        tableModel.addRow(row);
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this, "Error searching products.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
    // Check if any part of the product data contains the search term
    private boolean containsSearchTerm(String[] parts, String searchTerm) {
        for (String part : parts) {
            if (part.toLowerCase().contains(searchTerm)) {
                return true;
            }
        }
        return false;
    }
}