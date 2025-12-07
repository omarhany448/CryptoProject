#include "cryptodesk.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QGraphicsDropShadowEffect>
#include <QRegularExpression>
#include <QInputDialog>
#include <QSettings>

// Include all cipher headers
<<<<<<< HEAD
=======
#include "historydialog.h"
>>>>>>> master
#include "caesar.h"
#include "htmlexporter.h"
#include "playfair.h"
#include "hill.h"
#include "multiplicative.h"
#include "affine.h"
#include "dna.h"
#include "vigenere.h"
#include "autokey.h"
#include "vernam.h"
#include "transposition.h"
#include "rsa.h"
#include "customRSA.h"
#include "dialogutils.h"
#include "analysisdialog.h"

#include <QRandomGenerator>

// Helper function for RSA key generation
#include <tuple>

CryptoDesk::CryptoDesk(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("🔐 CryptoDesk – Modular Encryption");
    resize(700, 650);

    QWidget *central = new QWidget(this);
    setCentralWidget(central);

<<<<<<< HEAD
=======
// ----- Dark/Light Styles -----
    QString darkStyle = R"(
        QWidget { background-color: #1e1e1e; color: #f0f0f0; font-family: Segoe UI, Helvetica, Arial; font-size: 11pt; }
        QLineEdit, QPlainTextEdit, QComboBox { background-color: #2d2d30; color: #ffffff; border: 1px solid #3c3c3c; border-radius: 5px; padding: 5px; }
        QPushButton { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #138496, stop:1 #138496); color: #ffffff; border-radius: 6px; padding: 8px 15px; }
        QPushButton:hover { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #17a2b8, stop:1 #17a2b8); }
    )";

    QString lightStyle = R"(
        QWidget { background-color: #f0f0f0; color: #000000; font-family: Segoe UI, Helvetica, Arial; font-size: 11pt; }
        QLineEdit, QPlainTextEdit, QComboBox { background-color: #ffffff; color: #000000; border: 1px solid #ccc; border-radius: 5px; padding: 5px; }
        QPushButton { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #000000, stop:1 #000000); color: #ffffff; border-radius: 6px; padding: 8px 15px; }
        QPushButton:hover { background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #d0d0d0, stop:1 #b0b0b0);
                            color: #000000;
                        }
    )";

    
    // ----- Header -----
>>>>>>> master
    QLabel *appTitle = new QLabel("CryptoDesk");
    appTitle->setStyleSheet("font-size: 22px; font-weight: bold; color: white; margin-left: 5px;");
    appTitle->setAlignment(Qt::AlignCenter);

    QPushButton *aboutBtn = new QPushButton("About");
    aboutBtn->setCursor(Qt::PointingHandCursor);
<<<<<<< HEAD
    aboutBtn->setStyleSheet("background: transparent; color: #17a2b8; font-weight: bold; border: none; font-size: 14px;");
=======
>>>>>>> master
    aboutBtn->setStyleSheet(
        "QPushButton {"
        "   background-color: transparent;"
        "   color: #17a2b8;"
        "   font-weight: bold;"
        "   font-size: 14px;"
        "   border-radius: 15px;"
        "   border: none;"
        "}"
        "QPushButton:hover {"
        "color: white;"
        "   background-color: #138496;"
<<<<<<< HEAD
        "}");
=======
        "}"
        );
    QPushButton *historyBtn = new QPushButton("History");
    historyBtn->setCursor(Qt::PointingHandCursor);
    historyBtn->setStyleSheet(
        "QPushButton {"
        "   background-color: transparent;"
        "   color: #17a2b8;"
        "   font-weight: bold;"
        "   font-size: 14px;"
        "   border-radius: 15px;"
        "   border: none;"
        "}"
        "QPushButton:hover {"
        "   color: white;"
        "   background-color: #138496;"
        "}"
        );
    connect(historyBtn, &QPushButton::clicked, [=](){
        historyDialog->show();
    });

 // ----- Dark/Light Theme Button -----
    QPushButton *themeBtn = new QPushButton("🌙");
    themeBtn->setCursor(Qt::PointingHandCursor);
    themeBtn->setStyleSheet(
        "QPushButton { background-color: transparent; color: #17a2b8; font-weight: bold; font-size: 14px; border-radius: 15px; border: none; }"
        "QPushButton:hover { color: white; background-color: #138496; }"
        );

    bool isDark = true;
    this->setStyleSheet(darkStyle);

    connect(themeBtn, &QPushButton::clicked, [=, &isDark]() mutable {
        if(isDark) {
            this->setStyleSheet(lightStyle);
            themeBtn->setText("☀️");
            appTitle->setStyleSheet("font-size: 22px; font-weight: bold; color: black; margin-left: 40px;");
            isDark = false;
        } else {
            this->setStyleSheet(darkStyle);
            themeBtn->setText("🌙");
            appTitle->setStyleSheet("font-size: 22px; font-weight: bold; color: white; margin-left: 40px;");
            isDark = true;
        }
        QSettings settings("MyCompany", "CryptoDesk"); // حفظ الثيم باستخدام QSettings
        settings.setValue("isDarkTheme", isDark);
    });

QHBoxLayout *headerLayout = new QHBoxLayout();
    headerLayout->addStretch();
    headerLayout->addStretch();
    headerLayout->addWidget(appTitle);
    headerLayout->addStretch();
    headerLayout->addWidget(aboutBtn);
    headerLayout->addWidget(historyBtn);
    headerLayout->addWidget(themeBtn, 0, Qt::AlignRight);

    // ----- Input Fields -----
>>>>>>> master
    QLabel *labelText = new QLabel("Enter Text:");
    inputText = new QLineEdit();
    inputText->setStyleSheet("padding: 5px;");

    QLabel *labelKey = new QLabel("Key a:");
    keyInput = new QLineEdit();
<<<<<<< HEAD
    inputText->setStyleSheet("padding: 5px;");
=======
    keyInput->setStyleSheet("padding: 5px;");
>>>>>>> master

    labelKey2 = new QLabel("Key b:");
    keyInput2 = new QLineEdit();
    keyInput2->setPlaceholderText("Second key b for Affine");
<<<<<<< HEAD
    inputText->setStyleSheet("padding: 5px;");
    labelKey2->setVisible(false);
    keyInput2->setVisible(false);

    QLabel *labelAlgo = new QLabel("Algorithm:");
    algoCombo = new QComboBox();
    algoCombo->addItem("Caesar Cipher");
    algoCombo->addItem("Playfair Cipher");
    algoCombo->addItem("Hill Cipher (2x2)");
    algoCombo->addItem("Multiplicative Cipher");
    algoCombo->addItem("Affine Cipher");
    algoCombo->addItem("DNA Cipher");
    algoCombo->addItem("Vigenère Cipher");
    algoCombo->addItem("Autokey Cipher");
    algoCombo->addItem("Vernam Cipher");
    algoCombo->addItem("Rail Fence Cipher");
    algoCombo->addItem("Columnar Cipher");
    algoCombo->addItem("Row Transposition Cipher");
    algoCombo->addItem("RSA Cipher");
    algoCombo->addItem("Custom RSA Cipher");
=======
    labelKey2->setVisible(false);
    keyInput2->setVisible(false);

    // ----- Algorithm ComboBox -----
    QLabel *labelAlgo = new QLabel("Algorithm:");
    algoCombo = new QComboBox();
    algoCombo->addItems({
        "Select an algorithm",
        "Caesar Cipher", "Playfair Cipher", "Hill Cipher (2x2)",
        "Multiplicative Cipher", "Affine Cipher", "DNA Cipher",
        "Vigenère Cipher", "Autokey Cipher", "Vernam Cipher",
        "Rail Fence Cipher", "Columnar Cipher", "Row Transposition Cipher",
        "RSA Cipher", "Custom RSA Cipher"
    });
>>>>>>> master
    algoCombo->setStyleSheet("margin-bottom: 5px;");

    algoInfo = new QLabel("Select an algorithm to see info.");

    QPushButton *helpBtn = new QPushButton("?");
    helpBtn->setFixedSize(30, 30);
    helpBtn->setCursor(Qt::PointingHandCursor);
    helpBtn->setToolTip("Algorithm Guide");
    helpBtn->setStyleSheet(
        "QPushButton { background-color: transparent; color: #138496; font-weight: bold; font-size: 18px; border-radius: 15px; border: 1px solid white; padding: 0px; }"
        "QPushButton:hover { background-color: white; }"
        );
<<<<<<< HEAD
        "}");
=======
        "}"
        );

>>>>>>> master
    QHBoxLayout *algoLayout = new QHBoxLayout();
    algoLayout->addWidget(algoCombo);
    algoLayout->addWidget(helpBtn);

<<<<<<< HEAD
=======

    // ----- Buttons -----
>>>>>>> master
    QPushButton *encryptBtn = new QPushButton("Encrypt");
    QPushButton *decryptBtn = new QPushButton("Decrypt");
    QPushButton *fileBtn = new QPushButton("Encrypt File");
    generateKeyBtn = new QPushButton("Generate RSA Key");
    generateKeyBtn->setVisible(false);

    publicKeyOutput = new QLineEdit();
    privateKeyOutput = new QLineEdit();
<<<<<<< HEAD

    publicKeyOutput->setReadOnly(true);
    privateKeyOutput->setReadOnly(true);

=======
    publicKeyOutput->setReadOnly(true);
    privateKeyOutput->setReadOnly(true);
>>>>>>> master
    publicKeyOutput->setVisible(false);
    privateKeyOutput->setVisible(false);

    QPushButton *analyzeBtn = new QPushButton("Analyze");
    addShadow(analyzeBtn);

    importBtn = new QPushButton("Lab Report System");
    addShadow(importBtn);

    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(encryptBtn);
    btnLayout->addWidget(decryptBtn);
    btnLayout->addWidget(fileBtn);
    btnLayout->addWidget(generateKeyBtn);
    btnLayout->addWidget(analyzeBtn);
    btnLayout->addWidget(importBtn);

    outputText = new QPlainTextEdit();
    outputText->setReadOnly(true);
    outputText->setStyleSheet("margin-top: 5px;");

    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->addLayout(headerLayout);
    layout->addWidget(labelText);
    layout->addWidget(inputText);
    layout->addWidget(labelKey);
    layout->addWidget(keyInput);
    layout->addWidget(labelKey2);
    layout->addWidget(keyInput2);
    layout->addWidget(labelAlgo);
    layout->addLayout(algoLayout);
    layout->addLayout(btnLayout);
<<<<<<< HEAD
=======

>>>>>>> master
    labelPub = new QLabel("Public Key (n, e):");
    labelPub->setVisible(false);
    layout->addWidget(labelPub);
    layout->addWidget(publicKeyOutput);

    labelPriv = new QLabel("Private Key (n, d):");
    labelPriv->setVisible(false);
    layout->addWidget(labelPriv);
    layout->addWidget(privateKeyOutput);

    QPushButton *clearBtn = new QPushButton("Clear All");
    btnLayout->addWidget(clearBtn);

    layout->addWidget(outputText);

    addShadow(encryptBtn);
    addShadow(decryptBtn);
    addShadow(fileBtn);
    addShadow(generateKeyBtn);
    addShadow(clearBtn);

<<<<<<< HEAD
=======
    // ----- Initialize HistoryDialog -----
    historyDialog = new HistoryDialog(this);

    // ----- Connections -----
>>>>>>> master
    connect(encryptBtn, &QPushButton::clicked, this, &CryptoDesk::encryptText);
    connect(decryptBtn, &QPushButton::clicked, this, &CryptoDesk::decryptText);
    connect(fileBtn, &QPushButton::clicked, this, &CryptoDesk::encryptFile);
    connect(algoCombo, &QComboBox::currentTextChanged, this, &CryptoDesk::updateAlgoInfo);

    connect(helpBtn, &QPushButton::clicked, [=](){
        DialogUtils::showAlgorithmHelp(this, algoCombo->currentText());
    });

    connect(aboutBtn, &QPushButton::clicked, [=](){
        DialogUtils::showAbout(this);
    });

    connect(generateKeyBtn, &QPushButton::clicked, [=](){
        auto [n,e,d] = generateRSAKeys();
        publicKeyOutput->setText(QString("(%1, %2)").arg(n).arg(e));
        privateKeyOutput->setText(QString("(%1, %2)").arg(n).arg(d));
    });

    connect(clearBtn, &QPushButton::clicked, [=](){
        inputText->clear();
        keyInput->clear();
        keyInput2->clear();
        outputText->clear();
        publicKeyOutput->clear();
        privateKeyOutput->clear();
        inputText->setFocus();
    });

    connect(analyzeBtn, &QPushButton::clicked, [=](){
        QString textToAnalyze = outputText->toPlainText();
        if (textToAnalyze.isEmpty()) {
            textToAnalyze = inputText->text();
        }
<<<<<<< HEAD

=======
>>>>>>> master
        if (textToAnalyze.isEmpty()) {
            QMessageBox::warning(this, "Empty", "No text to analyze!");
            return;
        }
<<<<<<< HEAD

=======
>>>>>>> master
        AnalysisDialog dlg(textToAnalyze, this);
        dlg.exec();
    });

    connect(importBtn, &QPushButton::clicked, this, &CryptoDesk::handleLabReport);
<<<<<<< HEAD
    updateAlgoInfo();
}

=======

    updateAlgoInfo();
}


>>>>>>> master
void CryptoDesk::updateAlgoInfo() {
    QString algo = algoCombo->currentText();
    importBtn->setVisible(false);
    keyInput2->setVisible(false);
    labelKey2->setVisible(false);

    generateKeyBtn->setVisible(false);
    labelPub->setVisible(false);
    publicKeyOutput->setVisible(false);
    labelPriv->setVisible(false);
    privateKeyOutput->setVisible(false);

    keyInput2->setVisible(false);
    if (algo == "Caesar Cipher"){
        algoInfo->setText("Caesar Cipher: shift letters by a numeric key.");
        inputText->setPlaceholderText("Enter a text ( e.g.: Hello ) ");
        keyInput->setPlaceholderText("Enter Number as a key ( e.g.: 2 ) ");
    }
    else if (algo == "Playfair Cipher"){
        algoInfo->setText("Playfair Cipher: uses digraphs and a keyword matrix.");
        inputText->setPlaceholderText("Enter a text ( e.g.: Hello ) ");
        keyInput->setPlaceholderText("Enter a text as a key ( e.g.: PlayfairExample ) ");
        }
    else if (algo == "Hill Cipher (2x2)"){
        algoInfo->setText("Hill Cipher 2x2: uses 2x2 matrix multiplication.");
        inputText->setPlaceholderText("Enter a text ( e.g.: Hi ) ");
        keyInput->setPlaceholderText("Enter 4 letters without any spaces ( e.g.: Test ) ");
    }
    else if (algo=="Multiplicative Cipher"){
        algoInfo->setText("Multiplicative Cipher: multiply letters by key modulo 26 (key must be coprime with 26).");
        inputText->setPlaceholderText("Enter a Text ( e.g.: Hello ) ");
        keyInput->setPlaceholderText("Enter A Number That Is Coprime With 26 ( e.g.: 3 ) ");
    }
    else if (algo=="Affine Cipher") {
        algoInfo->setText("Affine Cipher: E(x) = (a*x + b) mod 26, 'a' coprime with 26");
        keyInput2->setVisible(true);
        labelKey2->setVisible(true);
        inputText->setPlaceholderText("Enter a text ( e.g.: Hello ) ");
        keyInput->setPlaceholderText("Enter A Number That Is Coprime With 26 ( e.g.: 5 ) ");
        keyInput2->setPlaceholderText("Enter Number as a key ( e.g.: 8 ) ");
    }
    else if (algo == "DNA Cipher"){
        importBtn->setVisible(true);
        algoInfo->setText("DNA Cipher: encodes text using nucleotide mapping.");
        inputText->setPlaceholderText("Enter a text ( e.g.: Hello World! ) ");
        keyInput->setPlaceholderText("Enter a text as a key ( e.g.: My Secret Key ) ");
    }
    else if (algo == "Vigenère Cipher"){
        algoInfo->setText("Vigenère Cipher: polyalphabetic cipher using a keyword.");
        inputText->setPlaceholderText("Enter a text ( e.g.: Lemon ) ");
        keyInput->setPlaceholderText("Enter Text as a key ( e.g.: Pizza ) ");
    }
    else if (algo == "Autokey Cipher"){
        algoInfo->setText("Autokey Cipher: extends the key with plaintext.");
        inputText->setPlaceholderText("Enter a text ( e.g.: HELLO ) ");
        keyInput->setPlaceholderText("Enter Text as a key ( e.g.: N ) ");
    }
    else if (algo == "Vernam Cipher"){
        algoInfo->setText("Vernam Cipher: XOR with a one-time pad key.");
        inputText->setPlaceholderText("Enter a text ( e.g.: HELLO ) ");
        keyInput->setPlaceholderText("Enter Text as a key ( e.g.: SON ) ");
    }
    else if (algo == "Rail Fence Cipher"){
        algoInfo->setText("Rail Fence Cipher: transposition using zigzag pattern.");
        inputText->setPlaceholderText("Enter a text ( e.g.: Meet Me After The Party ) ");
        keyInput->setPlaceholderText("Enter a Number as a key ( e.g.: 2 ) ");
    }
    else if (algo == "Columnar Cipher"){
        algoInfo->setText("Columnar Cipher: text arranged in columns based on key.");
        inputText->setPlaceholderText("Enter a text ( e.g.: Meet Me After The Party ) ");
        keyInput->setPlaceholderText("Enter Number of columns as a key ( e.g.: 3 ) ");
    }
    else if (algo == "Row Transposition Cipher"){
        algoInfo->setText("Row Transposition Cipher: permutes rows according to key.");
        inputText->setPlaceholderText("Enter a text ( e.g.: attack postponed until two am ) ");
        keyInput->setPlaceholderText("Enter numbers according to the desired array order ( e.g.: 412367 ) ");
    }
    else if (algo == "RSA Cipher"){
        algoInfo->setText("RSA Cipher: asymmetric encryption using public/private keys.");
        inputText->setPlaceholderText("Enter a Text ( e.g.: Hello ) ");
        keyInput->setPlaceholderText("Enter a key with n , e  ( e.g.: (33,7) ) ");
        generateKeyBtn->setVisible(true);
        labelPub->setVisible(true);
        publicKeyOutput->setVisible(true);
        labelPriv->setVisible(true);
        privateKeyOutput->setVisible(true);
    }
    else if (algo == "Custom RSA Cipher"){
        algoInfo->setText("RSA Cipher: asymmetric encryption using p and q .");
        keyInput2->setVisible(true);
        labelKey2->setVisible(true);
        inputText->setPlaceholderText("Enter a Text ( e.g.: Hello ) ");
        keyInput->setPlaceholderText("Enter the the value of p ( e.g.: 7 ) ");
        keyInput2->setPlaceholderText("Enter the the value of q ( e.g.: 11 ) ");
    }
}

bool CryptoDesk::validateInputs() {
    QString algo = algoCombo->currentText();
    QString key1 = keyInput->text().trimmed();
    QString key2 = keyInput2->text().trimmed();

    if (key1.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Key cannot be empty!");
        return false;
    }
    if (key1.contains(" ") && algo != "RSA Cipher") {
        QMessageBox::warning(this, "Input Error", "Remove Spaces!");
        return false;
    }

    QRegularExpression isNumber("^[0-9]+$");
    QRegularExpression isText("^[a-zA-Z]+$");

    // =========================================================
    // المجموعة الأولى: خوارزميات تحتاج أرقام فقط (Integer Keys)
    // =========================================================
    if (algo == "Caesar Cipher" ||
        algo == "Multiplicative Cipher" ||
        algo == "Rail Fence Cipher" ||
        algo == "Columnar Cipher") {

        if (!isNumber.match(key1).hasMatch()) {
            QMessageBox::warning(this, "Input Error",
                                 QString("The key for %1 must be a valid Integer number!").arg(algo));
            return false;
        }

        if (algo == "Multiplicative Cipher" && key1.toInt() == 0) {
            QMessageBox::warning(this, "Input Error", "Key cannot be zero!");
            return false;
        }
    }

    // =========================================================
    // المجموعة الثانية: خوارزميات تحتاج حروف فقط (String Keys)
    // =========================================================
    else if (algo == "Playfair Cipher" ||
             algo == "Vigenère Cipher" ||
             algo == "Autokey Cipher" ||
             algo == "Vernam Cipher" ||
             algo == "DNA Cipher") {

        if (!isText.match(key1).hasMatch()) {
            QMessageBox::warning(this, "Input Error",
                                 QString("The key for %1 must contain English letters only (No numbers or symbols)!").arg(algo));
            return false;
        }
    }

    // =========================================================
    // المجموعة الثالثة: حالات خاصة (Hill, Row Transposition)
    // =========================================================
    else if (algo == "Hill Cipher (2x2)") {
        if (!isText.match(key1).hasMatch() || key1.length() != 4) {
            QMessageBox::warning(this, "Input Error",
                                 "Hill Cipher (2x2) key must be exactly 4 letters!");
            return false;
        }
    }
    else if (algo == "Row Transposition Cipher") {

        if (!isNumber.match(key1).hasMatch()) {
            QMessageBox::warning(this, "Input Error", "Row Transposition key usually consists of numbers (e.g., 4312)!");
            return false;
        }
    }

    // =========================================================
    // المجموعة الرابعة: خوارزميات بمفتاحين (Affine, Custom RSA)
    // =========================================================
    else if (algo == "Affine Cipher") {
        if (!isNumber.match(key1).hasMatch()) {
            QMessageBox::warning(this, "Input Error", "Key 'a' must be a number!");
            return false;
        }
        if (key2.isEmpty() || !isNumber.match(key2).hasMatch()) {
            QMessageBox::warning(this, "Input Error", "Key 'b' must be a number!");
            return false;
        }
    }
    else if (algo == "Custom RSA Cipher") {
        if (!isNumber.match(key1).hasMatch()) {
            QMessageBox::warning(this, "Input Error", "P must be a number!");
            return false;
        }
        if (key2.isEmpty() || !isNumber.match(key2).hasMatch()) {
            QMessageBox::warning(this, "Input Error", "Q must be a number!");
            return false;
        }
    }

    return true;
}


void CryptoDesk::encryptText() {
    QString text = inputText->text();
    QString algo = algoCombo->currentText();
    QString result;

<<<<<<< HEAD
    if (text.isEmpty()) { QMessageBox::warning(this,"Warning","Please enter text!"); return; }

    if (!validateInputs()) return;

=======
    if (text.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter text!");
        return;
    }

    if (!validateInputs()) return;

    // ----- تشفير حسب الخوارزمية -----
>>>>>>> master
    if (algo == "Caesar Cipher") result = caesarEncrypt(text, keyInput->text().toInt());
    else if (algo == "Playfair Cipher") result = playfairEncrypt(text, keyInput->text());
    else if (algo == "Multiplicative Cipher") result = multiplicativeEncrypt(text, keyInput->text().toInt());
    else if (algo == "Hill Cipher (2x2)") result = hillEncrypt(text, keyInput->text());
<<<<<<< HEAD
    else if (algo == "Affine Cipher") { int a = keyInput->text().toInt(); int b = keyInput2->text().toInt(); result = affineEncrypt(text,a,b);}
    else if (algo == "DNA Cipher") result = dnaEncrypt(text, keyInput->text());
    else if (algo == "Vigenère Cipher") result = vigenereEncrypt(text,keyInput->text());
    else if (algo == "Autokey Cipher") result = autokeyEncrypt(text,keyInput->text());
    else if (algo == "Vernam Cipher") result = vernamEncrypt(text,keyInput->text());
    else if (algo == "Rail Fence Cipher") result = railFenceEncrypt(text,keyInput->text().toInt());
    else if (algo == "Columnar Cipher") {int a = keyInput->text().toInt(); result = columnarEncrypt(text,a);}
    else if (algo == "Row Transposition Cipher") result = rowTranspositionEncrypt(text,keyInput->text());
    else if (algo == "RSA Cipher") result = rsaEncrypt(text,keyInput->text(), keyInput2->text());
    else if (algo == "Custom RSA Cipher") {result = rsaEncryptCustom(text, keyInput->text(), keyInput2->text());}
    outputText->setPlainText(result);
=======
    else if (algo == "Affine Cipher") {
        int a = keyInput->text().toInt();
        int b = keyInput2->text().toInt();
        result = affineEncrypt(text, a, b);
    }
    else if (algo == "DNA Cipher") result = dnaEncrypt(text, keyInput->text());
    else if (algo == "Vigenère Cipher") result = vigenereEncrypt(text, keyInput->text());
    else if (algo == "Autokey Cipher") result = autokeyEncrypt(text, keyInput->text());
    else if (algo == "Vernam Cipher") result = vernamEncrypt(text, keyInput->text());
    else if (algo == "Rail Fence Cipher") result = railFenceEncrypt(text, keyInput->text().toInt());
    else if (algo == "Columnar Cipher") { int a = keyInput->text().toInt(); result = columnarEncrypt(text, a); }
    else if (algo == "Row Transposition Cipher") result = rowTranspositionEncrypt(text, keyInput->text());
    else if (algo == "RSA Cipher") result = rsaEncrypt(text, keyInput->text(), keyInput2->text());
    else if (algo == "Custom RSA Cipher") result = rsaEncryptCustom(text, keyInput->text(), keyInput2->text());

    // ----- عرض الناتج -----
    outputText->setPlainText(result);

    // ----- سجل العملية في History -----
    if (!result.isEmpty()) {
        QString shortInput = text;
        QString shortResult = result;

        // اختصار النصوص الطويلة لأناقة العرض
        if (shortInput.length() > 200) shortInput = shortInput.left(200) + "...";
        if (shortResult.length() > 200) shortResult = shortResult.left(200) + "...";

        historyDialog->addEntry("Encrypted", algo, shortInput, shortResult);
    }
>>>>>>> master
}

void CryptoDesk::decryptText() {
    QString text = inputText->text();
    QString algo = algoCombo->currentText();
    QString result;

<<<<<<< HEAD
    if (text.isEmpty()) { QMessageBox::warning(this,"Warning","Please enter text!"); return; }

    if (!validateInputs()) return;

=======
    if (text.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter text!");
        return;
    }

    if (!validateInputs()) return;

    // ----- فك التشفير حسب الخوارزمية -----
>>>>>>> master
    if (algo == "Caesar Cipher") result = caesarDecrypt(text, keyInput->text().toInt());
    else if (algo == "Playfair Cipher") result = playfairDecrypt(text, keyInput->text());
    else if (algo == "Multiplicative Cipher") result = multiplicativeDecrypt(text, keyInput->text().toInt());
    else if (algo == "Hill Cipher (2x2)") result = hillDecrypt(text, keyInput->text());
<<<<<<< HEAD
    else if (algo == "Affine Cipher") { int a = keyInput->text().toInt(); int b = keyInput2->text().toInt(); result = affineDecrypt(text,a,b);}
    else if (algo == "DNA Cipher") result = dnaDecrypt(text, keyInput->text());
    else if (algo == "Vigenère Cipher") result = vigenereDecrypt(text,keyInput->text());
    else if (algo == "Autokey Cipher") result = autokeyDecrypt(text,keyInput->text());
    else if (algo == "Vernam Cipher") result = vernamDecrypt(text,keyInput->text());
    else if (algo == "Rail Fence Cipher") result = railFenceDecrypt(text,keyInput->text().toInt());
    else if (algo == "Columnar Cipher") {int a = keyInput->text().toInt(); result = columnarDecrypt(text,a);}
    else if (algo == "Row Transposition Cipher") result = rowTranspositionDecrypt(text,keyInput->text());
    else if (algo == "RSA Cipher") result = rsaDecrypt(text,keyInput->text(), keyInput2->text());
    else if (algo == "Custom RSA Cipher") {result = rsaDecryptCustom(text, keyInput->text(), keyInput2->text());}
    outputText->setPlainText(result);
}

void CryptoDesk::encryptFile() {
    QString fileName = QFileDialog::getOpenFileName(this,"Select file");
    if(fileName.isEmpty()) return;

    QFile f(fileName);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text)) return;
=======
    else if (algo == "Affine Cipher") {
        int a = keyInput->text().toInt();
        int b = keyInput2->text().toInt();
        result = affineDecrypt(text, a, b);
    }
    else if (algo == "DNA Cipher") result = dnaDecrypt(text, keyInput->text());
    else if (algo == "Vigenère Cipher") result = vigenereDecrypt(text, keyInput->text());
    else if (algo == "Autokey Cipher") result = autokeyDecrypt(text, keyInput->text());
    else if (algo == "Vernam Cipher") result = vernamDecrypt(text, keyInput->text());
    else if (algo == "Rail Fence Cipher") result = railFenceDecrypt(text, keyInput->text().toInt());
    else if (algo == "Columnar Cipher") { int a = keyInput->text().toInt(); result = columnarDecrypt(text, a); }
    else if (algo == "Row Transposition Cipher") result = rowTranspositionDecrypt(text, keyInput->text());
    else if (algo == "RSA Cipher") result = rsaDecrypt(text, keyInput->text(), keyInput2->text());
    else if (algo == "Custom RSA Cipher") result = rsaDecryptCustom(text, keyInput->text(), keyInput2->text());

    // ----- عرض الناتج -----
    outputText->setPlainText(result);

    // ----- سجل العملية في History -----
    if (!result.isEmpty()) {
        QString shortInput = text;
        QString shortResult = result;

        // اختصار النصوص الطويلة لأناقة العرض
        if (shortInput.length() > 200) shortInput = shortInput.left(200) + "...";
        if (shortResult.length() > 200) shortResult = shortResult.left(200) + "...";

        historyDialog->addEntry("Decrypted", algo, shortInput, shortResult);
    }
}

void CryptoDesk::encryptFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Select file");
    if (fileName.isEmpty()) return;

    QFile f(fileName);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) return;
>>>>>>> master
    QTextStream in(&f);
    QString content = in.readAll();
    f.close();

    QString algo = algoCombo->currentText();
    QString result;

<<<<<<< HEAD
    if (algo == "Caesar Cipher") result = caesarEncrypt(content,keyInput->text().toInt());
    else if (algo == "Playfair Cipher") result = playfairEncrypt(content,keyInput->text());
    else if (algo == "Multiplicative Cipher") result = multiplicativeEncrypt(content,keyInput->text().toInt());
    else if (algo == "Hill Cipher (2x2)") result = hillEncrypt(content,keyInput->text());
    else if (algo == "Affine Cipher") { int a = keyInput->text().toInt(); int b = keyInput2->text().toInt(); result = affineEncrypt(content,a,b);}
    else if (algo == "DNA Cipher") result = dnaEncrypt(content, keyInput->text());
    else if (algo == "Vigenère Cipher") result = vigenereEncrypt(content,keyInput->text());
    else if (algo == "Autokey Cipher") result = autokeyEncrypt(content,keyInput->text());
    else if (algo == "Vernam Cipher") result = vernamEncrypt(content,keyInput->text());
    else if (algo == "Rail Fence Cipher") result = railFenceEncrypt(content,keyInput->text().toInt());
    else if (algo == "Columnar Cipher") {int a = keyInput->text().toInt(); result = columnarEncrypt(content,a);}
    else if (algo == "Row Transposition Cipher") result = rowTranspositionEncrypt(content,keyInput->text());
    else if (algo == "RSA Cipher") result = rsaEncrypt(content,keyInput->text(), keyInput2->text());
    else if (algo == "Custom RSA Cipher") {
        result = rsaEncryptCustom(content, keyInput->text(), keyInput2->text());
    }
    QString save = QFileDialog::getSaveFileName(this,"Save encrypted file");
    if(save.isEmpty()) return;

    QFile out(save);
    // out.open(QIODevice::WriteOnly | QIODevice::Text);
=======
    // ----- تشفير حسب الخوارزمية -----
    if (algo == "Caesar Cipher") result = caesarEncrypt(content, keyInput->text().toInt());
    else if (algo == "Playfair Cipher") result = playfairEncrypt(content, keyInput->text());
    else if (algo == "Multiplicative Cipher") result = multiplicativeEncrypt(content, keyInput->text().toInt());
    else if (algo == "Hill Cipher (2x2)") result = hillEncrypt(content, keyInput->text());
    else if (algo == "Affine Cipher") { int a = keyInput->text().toInt(); int b = keyInput2->text().toInt(); result = affineEncrypt(content, a, b); }
    else if (algo == "DNA Cipher") result = dnaEncrypt(content, keyInput->text());
    else if (algo == "Vigenère Cipher") result = vigenereEncrypt(content, keyInput->text());
    else if (algo == "Autokey Cipher") result = autokeyEncrypt(content, keyInput->text());
    else if (algo == "Vernam Cipher") result = vernamEncrypt(content, keyInput->text());
    else if (algo == "Rail Fence Cipher") result = railFenceEncrypt(content, keyInput->text().toInt());
    else if (algo == "Columnar Cipher") { int a = keyInput->text().toInt(); result = columnarEncrypt(content, a); }
    else if (algo == "Row Transposition Cipher") result = rowTranspositionEncrypt(content, keyInput->text());
    else if (algo == "RSA Cipher") result = rsaEncrypt(content, keyInput->text(), keyInput2->text());
    else if (algo == "Custom RSA Cipher") result = rsaEncryptCustom(content, keyInput->text(), keyInput2->text());

    // ----- حفظ الملف -----
    QString save = QFileDialog::getSaveFileName(this, "Save encrypted file");
    if (save.isEmpty()) return;

    QFile out(save);
>>>>>>> master
    if (!out.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Cannot create output file!");
        return;
    }
    QTextStream s(&out);
    s << result;
    out.close();

<<<<<<< HEAD
    QMessageBox::information(this,"Done","File encrypted successfully!");
=======
    QMessageBox::information(this, "Done", "File encrypted successfully!");

    // ----- سجل العملية في History -----
    QString fileShortName = QFileInfo(fileName).fileName();
    historyDialog->addEntry("Encrypted", algo, fileShortName, "Output saved to: " + QFileInfo(save).fileName());
>>>>>>> master
}

void CryptoDesk::addShadow(QWidget *widget) {
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(widget);
    shadow->setBlurRadius(15);
    shadow->setOffset(3,3);
    shadow->setColor(QColor(0,0,0,160));
    widget->setGraphicsEffect(shadow);
}

void CryptoDesk::handleLabReport() {
    // 1. نسأل المستخدم هو عايز إيه
    QMessageBox msgBox;
    msgBox.setWindowTitle("Lab Report System");
    msgBox.setText("Please select an action:");
    msgBox.setIcon(QMessageBox::Question);

    // بنضيف زراير مخصصة
    QAbstractButton *pExportBtn = msgBox.addButton("📝 Generate New Report", QMessageBox::YesRole);
    QAbstractButton *pImportBtn = msgBox.addButton("📂 Open Existing Report", QMessageBox::NoRole);
    msgBox.addButton(QMessageBox::Cancel);

    msgBox.exec();

    // 2. نشوف المستخدم اختار إيه
    if (msgBox.clickedButton() == pExportBtn) {
        // --- مسار الـ EXPORT ---

        // أ) التحقق من المدخلات (Validation)
        if (inputText->text().isEmpty()) {
            QMessageBox::warning(this, "Missing Data", "Cannot generate report: Diagnosis result (Text) is empty!");
            return; // وقف هنا متكملش
        }
        if (keyInput->text().isEmpty()) {
            QMessageBox::warning(this, "Missing Data", "Cannot generate report: Sample ID (Key) is empty!");
            return; // وقف هنا متكملش
        }

        // ب) لو كله تمام، نفذ
        performExport();

    } else if (msgBox.clickedButton() == pImportBtn) {
        // --- مسار الـ IMPORT ---
        // هنا مش محتاجين نتأكد من inputs لأننا لسه هنملاهم من الملف
        performImport();
    }
}

void CryptoDesk::performExport() {
    // 1. ناخد البيانات الجاهزة (إحنا اتأكدنا فوق إنها موجودة خلاص)
    QString diagnosis = inputText->text();
    QString sampleID = keyInput->text();

    // (اختياري) نطلب اسم المريض
    bool ok;
    QString patientName = QInputDialog::getText(this, "Patient Data", "Enter Patient Name:", QLineEdit::Normal, "John Doe", &ok);
    if (!ok) return;

    // 2. التشفير
    QString encryptedDNA = dnaEncrypt(diagnosis, sampleID);

    // 3. فتح نافذة الحفظ
    QString fileName = QFileDialog::getSaveFileName(this, "Save Report", "Report.html", "HTML Files (*.html)");
    if (fileName.isEmpty()) return;

    // 4. الحفظ باستخدام الكلاس اللي عملناه
    if (HtmlExporter::saveLabReport(fileName, patientName, sampleID, encryptedDNA)) {
        QMessageBox::information(this, "Success", "Report Generated!");
    }
}

void CryptoDesk::performImport() {
    // 1. فتح نافذة الاستيراد
    QString fileName = QFileDialog::getOpenFileName(this, "Select Report", "", "HTML Files (*.html)");
    if (fileName.isEmpty()) return;

    // 2. استخدام الكلاس الخارجي للقراءة
    ReportData data = HtmlExporter::parseLabReport(fileName);

    if (data.isValid) {
        // فك التشفير
        QString result = dnaDecrypt(data.encryptedData, data.sampleID);

        // عرض البيانات
        algoCombo->setCurrentText("DNA Cipher");
        inputText->setText(result);
        keyInput->setText(data.sampleID);
        outputText->setPlainText("Report Loaded:\n" + result);

        QMessageBox::information(this, "Done", "Report Decoded Successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Invalid Report File!");
    }
}

void CryptoDesk::importHtmlReport() {
    // 1. نفتح الملف
    QString fileName = QFileDialog::getOpenFileName(this, "Select Lab Report", "", "HTML Files (*.html)");
    if (fileName.isEmpty()) return;

    // 2. نطلب من الكلاس الخارجي يحلل الملف ويرجعلنا البيانات
    ReportData data = HtmlExporter::parseLabReport(fileName);

    // 3. نتأكد إن البيانات سليمة ونعرضها
    if (data.isValid) {
        // نفك التشفير هنا في الواجهة (أو نستدعي دالة الفك)
        QString decryptedDiagnosis = dnaDecrypt(data.encryptedData, data.sampleID);

        // تحديث الواجهة
        algoCombo->setCurrentText("DNA Cipher");
        inputText->setText(decryptedDiagnosis);
        keyInput->setText(data.sampleID);
        outputText->setPlainText("Decrypted from HTML Report:\n" + decryptedDiagnosis);

        QMessageBox::information(this, "Success", "Report loaded and decrypted successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Invalid Report Format!\nCould not find Sample ID or DNA Data.");
    }
}
