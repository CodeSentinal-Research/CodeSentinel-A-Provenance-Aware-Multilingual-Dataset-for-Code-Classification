/**
 * Preload Script - Retail POS System
 *
 * Bridges the isolated renderer (browser) context to the Node.js main process
 * via Electron's contextBridge + ipcRenderer. The renderer accesses everything
 * through the global `window.api` object - no direct Node.js access.
 *
 * Channel naming convention:  domain:action  (e.g. 'db:health', 'settings:get')
 */

'use strict';

const { contextBridge, ipcRenderer } = require('electron');

contextBridge.exposeInMainWorld('api', {

  // Window controls (custom title bar)
  window: {
    minimize:  () => ipcRenderer.send('window:minimize'),
    maximize:  () => ipcRenderer.send('window:maximize'),
    close:     () => ipcRenderer.send('window:close'),
    /** Returns current maximized state. */
    isMaximized: () => ipcRenderer.invoke('window:isMaximized'),
    /** Subscribes to maximize/unmaximize. Returns an unsubscribe function. */
    onMaximizedChange: (cb) => {
      const listener = (_event, value) => cb(value);
      ipcRenderer.on('window:maximized', listener);
      return () => ipcRenderer.removeListener('window:maximized', listener);
    },
    /** Toggles the slim always-on-top compact/PiP widget mode. Returns the new compact state (boolean). */
    toggleCompactMode: () => ipcRenderer.invoke('window:toggleCompactMode'),
    /** Returns current compact-mode state. */
    isCompactMode: () => ipcRenderer.invoke('window:isCompactMode'),
    /** Subscribes to compact-mode changes. Returns an unsubscribe function. */
    onCompactModeChange: (cb) => {
      const listener = (_event, value) => cb(value);
      ipcRenderer.on('window:compactModeChanged', listener);
      return () => ipcRenderer.removeListener('window:compactModeChanged', listener);
    },
  },

  // Database health
  db: {
    /** Returns { status, tableCount, tables, missing, walMode, foreignKeys } */
    health: () => ipcRenderer.invoke('db:health'),
    /** Returns { unsyncedCount, oldestUnsyncedDate } */
    getSyncQueueStats: () => ipcRenderer.invoke('db:getSyncQueueStats'),
    /** Returns count of overdue unpaid promises */
    getOverduePromisesCount: () => ipcRenderer.invoke('db:getOverduePromisesCount'),
  },

  // Settings
  settings: {
    /** Returns Record<string, string> of all settings */
    getAll:  ()          => ipcRenderer.invoke('settings:getAll'),
    /** Returns single setting value or undefined */
    get:     (key)       => ipcRenderer.invoke('settings:get', key),
    /** Updates a setting. Returns { success: true } */
    update:  (key, value) => ipcRenderer.invoke('settings:update', key, value),
    /** Opens a native folder picker. Returns { canceled } or { canceled:false, path } */
    browseFolder: () => ipcRenderer.invoke('settings:browseFolder'),
    /** Opens a native image picker for the receipt logo. Returns { success, dataUri } or { canceled }. */
    pickReceiptLogo: () => ipcRenderer.invoke('settings:pickReceiptLogo'),
    /** Returns { dataUri } (or { dataUri: null }) for the saved receipt logo. */
    getReceiptLogo: () => ipcRenderer.invoke('settings:getReceiptLogo'),
    /** Clears the saved receipt logo. Returns { success } */
    removeReceiptLogo: () => ipcRenderer.invoke('settings:removeReceiptLogo'),
  },

  // Construction Projects
  projects: {
    /** Finds a project by name or creates one. Returns { success, id } */
    findOrCreate: (data) => ipcRenderer.invoke('projects:findOrCreate', data),
    /** All projects, most recently created first - for the New Sale autocomplete. */
    getAll: () => ipcRenderer.invoke('projects:getAll'),
    /** One row per project: invoice count, total spend, materials breakdown, primary customer. */
    getOverview: () => ipcRenderer.invoke('projects:getOverview'),
  },

  // Predictive Agricultural Analytics
  agri: {
    /** Regional crop planting-window reference data (informational only). */
    getCropCalendar: () => ipcRenderer.invoke('agri:getCropCalendar'),
    /** Reference fertilizer application rates per acre, by crop. */
    getDosageGuidelines: () => ipcRenderer.invoke('agri:getDosageGuidelines'),
    /** A customer's fertilizer purchases vs. the per-acre reference guideline for a crop, plus simple recommendations. */
    getCustomerFertilizerProgress: (customerId, cropName, months) => ipcRenderer.invoke('agri:getCustomerFertilizerProgress', customerId, cropName, months),
    /** All-time, all-customer sales totals for a crop's dosage-guideline products (qty + revenue). */
    getCropSalesBreakdown: (cropName) => ipcRenderer.invoke('agri:getCropSalesBreakdown', cropName),
    /** Predictive pre-order cards for crops whose sowing window opens soon: last season's demand vs current stock. */
    getSeasonalReorderSuggestions: (opts) => ipcRenderer.invoke('agri:getSeasonalReorderSuggestions', opts),
  },

  // Receipt History
  receipts: {
    /** Searches printed receipt history by product name, customer name, or general keyword (matched simultaneously). Empty query returns the most recent 100. */
    search: (query) => ipcRenderer.invoke('receipts:search', query),
    /** Reprints a saved invoice's receipt and logs the reprint. Returns { success, code?, message? } */
    reprint: (invoiceId) => ipcRenderer.invoke('receipts:reprint', invoiceId),
  },

  // Reports (Phase 6)
  reports: {
    /** Profit & Loss over [startDate,endDate] ISO. Returns { revenue, cogs, grossProfit, ... } */
    getProfitLoss:  (startDate, endDate) => ipcRenderer.invoke('reports:getProfitLoss', startDate, endDate),
    /** Aging AR bucketed by days overdue as of ISO date. */
    getAgingAR:     (asOfDate)           => ipcRenderer.invoke('reports:getAgingAR', asOfDate),
    /** Aging AP bucketed by days overdue as of ISO date. */
    getAgingAP:     (asOfDate)           => ipcRenderer.invoke('reports:getAgingAP', asOfDate),
    /** Non-bucketed receivables detail rows - one per outstanding invoice, sortable/filterable client-side. */
    getReceivablesDetail: ()             => ipcRenderer.invoke('reports:getReceivablesDetail'),
    /** Non-bucketed payables detail rows - one per unpaid/partial supplier installment, sortable/filterable client-side. */
    getPayablesDetail: ()                => ipcRenderer.invoke('reports:getPayablesDetail'),
    /** Sales grouped by item_category over [startDate,endDate] ISO. */
    getSalesSummary:(startDate, endDate) => ipcRenderer.invoke('reports:getSalesSummary', startDate, endDate),
    /** Sales time series for the dashboard. range: 'today' | 'week'. */
    getSalesSeries: (range)              => ipcRenderer.invoke('reports:getSalesSeries', range),
    /** Top products (qty + value) over a trailing window, sorted by 'value' or 'qty'. */
    getTopProducts: (days, limit, sortBy) => ipcRenderer.invoke('reports:getTopProducts', days, limit, sortBy),
    /** Daily sales value & quantity sold across the catalog over a trailing window. */
    getSalesQtyTrend: (days)             => ipcRenderer.invoke('reports:getSalesQtyTrend', days),
    /** Monthly profit over a trailing window of calendar months. */
    getMonthlyProfitTrend: (months)      => ipcRenderer.invoke('reports:getMonthlyProfitTrend', months),
    /** Profit trend bounded to [startDate,endDate], daily buckets for <=45 days, monthly buckets otherwise. */
    getProfitTrendForRange: (startDate, endDate) => ipcRenderer.invoke('reports:getProfitTrendForRange', startDate, endDate),
    /** Per-day POS usage (invoice count + total) over a trailing window. */
    getDailyActivity: (days)             => ipcRenderer.invoke('reports:getDailyActivity', days),
    /** Daily cash position cockpit: banks + register vs obligations due now and 7 days out. */
    getCashPosition: ()                  => ipcRenderer.invoke('reports:getCashPosition'),
    /** Renders a report ('pl'|'ar'|'ap'|'summary') to PDF and saves it via a native save dialog. */
    downloadPdf: (reportType, params)    => ipcRenderer.invoke('reports:downloadPdf', reportType, params),
    /** Builds a report ('pl'|'ar'|'ap'|'summary') as an Excel workbook and saves it via a native save dialog. */
    downloadExcel: (reportType, params)  => ipcRenderer.invoke('reports:downloadExcel', reportType, params),
  },

  // Profile
  profile: {
    /** Opens a native image picker, saves it, returns { success, dataUri } or { canceled }. */
    pickImage: () => ipcRenderer.invoke('profile:pickImage'),
    /** Returns { dataUri } (or { dataUri: null }) for the saved profile picture. */
    getImage: () => ipcRenderer.invoke('profile:getImage'),
  },

  // Backup (Phase 6)
  backup: {
    /** Runs an on-demand DB backup. `dir`, if given, wins over the saved backup_path setting and is persisted as the new one. Returns { success, file, timestamp } */
    run: (dir) => ipcRenderer.invoke('backup:run', dir),
    /** Picks a .db file and merges its data into the live database table-by-table (schema-tolerant). Returns { success, preRestoreBackupFile?, report?, canceled?, error? } */
    restore: () => ipcRenderer.invoke('backup:restore'),
  },

  app: {
    /** Relaunches the app (used after a restore). */
    relaunch: () => ipcRenderer.invoke('app:relaunch'),
    /** Subscribes to a tray-menu-triggered route change (hash path, e.g. '/sale-general'). Returns an unsubscribe function. */
    onNavigateTo: (cb) => {
      const listener = (_event, hashPath) => cb(hashPath);
      ipcRenderer.on('app:navigateTo', listener);
      return () => ipcRenderer.removeListener('app:navigateTo', listener);
    },
  },

  // Auth (Phase 2)
  auth: {
    /** Returns boolean - true if at least one user exists (skip setup wizard) */
    hasUsers: () => ipcRenderer.invoke('auth:hasUsers'),
    /** Creates a new user. Returns { success: true, userId } or { success: false, error } */
    createUser: (userData) => ipcRenderer.invoke('auth:createUser', userData),
    /** Logs in a user. Returns { success: true, user } or { success: false } */
    login: (username, password) => ipcRenderer.invoke('auth:login', username, password),
    /** Gets security questions if Recovery Master PIN is valid. Returns { success, q1, q2 } */
    getSecurityQuestions: (username, recoveryMaster) => ipcRenderer.invoke('auth:getSecurityQuestions', username, recoveryMaster),
    /** Recovers and resets credentials. Returns { success } or { success, error } */
    recoverPassword: (recoveryData) => ipcRenderer.invoke('auth:recoverPassword', recoveryData),
    /** Verifies a supervisor PIN. Returns boolean */
    verifySupervisorPin: (pin) => ipcRenderer.invoke('auth:verifySupervisorPin', pin),
    /** Verifies if running in automated UI test mode */
    isTestUi: () => ipcRenderer.invoke('auth:isTestUi'),
    /** Lists all users (no credentials). Returns array */
    listUsers: () => ipcRenderer.invoke('auth:listUsers'),
    /** Deletes a user account. Returns { success } or { success, error } */
    deleteUser: (userId) => ipcRenderer.invoke('auth:deleteUser', userId),
    /** Changes the login password after verifying the current one. Returns { success, error? } */
    changePassword: (username, currentPassword, newPassword) => ipcRenderer.invoke('auth:changePassword', username, currentPassword, newPassword),
  },

  // Units of Measure
  uom: {
    /** Returns array of { id, uom_name } */
    getAll: () => ipcRenderer.invoke('uom:getAll'),
    /** Creates a custom UOM. Returns { success, uomId } or { success, error } */
    create: (uomName) => ipcRenderer.invoke('uom:create', uomName),
  },

  // Product Catalog (Phase 4)
  items: {
    /** Creates a product. Returns { success, itemCode } or { success, error } */
    create: (itemData, sellableUnits) => ipcRenderer.invoke('items:create', itemData, sellableUnits),
    /** Updates a product. Returns { success } or { success, error } */
    update: (itemCode, itemData, sellableUnits) => ipcRenderer.invoke('items:update', itemCode, itemData, sellableUnits),
    /** Gets detailed product with sellable units. Returns { success, item } or { success, error } */
    get: (itemCode) => ipcRenderer.invoke('items:get', itemCode),
    /** Case-insensitive fuzzy search. Returns array of items */
    search: (query, typeFilter) => ipcRenderer.invoke('items:search', query, typeFilter),
    /** Deletes a product. Returns { success } or { success, error } */
    delete: (itemCode) => ipcRenderer.invoke('items:delete', itemCode),
    /** Products at/below the low-stock threshold, worst first. */
    getLowStock: () => ipcRenderer.invoke('items:getLowStock'),
    /** Suppliers each product has been bought from, keyed by item_code. */
    getSupplierUsage: () => ipcRenderer.invoke('items:getSupplierUsage'),
    /** Sale/purchase price change timeline for a product, newest first. */
    getPriceHistory: (itemCode) => ipcRenderer.invoke('items:getPriceHistory', itemCode),
    /** Full stock-in/sales history for one product (Product Intelligence & Lifecycle subpage). */
    getLifecycle: (itemCode) => ipcRenderer.invoke('items:getLifecycle', itemCode),
    /** Date-bounded stock/profit/velocity KPIs for one product. */
    getKpis: (itemCode, startDate, endDate) => ipcRenderer.invoke('items:getKpis', itemCode, startDate, endDate),
  },

  // Customers (Phase 5)
  customers: {
    /** Finds or creates customer. Returns { success, customer, merged } - merged is true when an existing customer with this name was matched instead of creating a new one. */
    findOrCreate: (customerData) => ipcRenderer.invoke('customers:findOrCreate', customerData),
    /** Fuzzy search by name/phone. Returns array of customers */
    search: (query) => ipcRenderer.invoke('customers:search', query),
    /** Returns all invoices for a customer (Khata ledger). */
    getInvoices: (customerId) => ipcRenderer.invoke('customers:getInvoices', customerId),
    /** Returns all customers with a non-zero outstanding balance (Khata Book). */
    getKhataList: () => ipcRenderer.invoke('customers:getKhataList'),
    /** Read-only khata credit-risk score (aging, broken promises, safe allowance) for the checkout risk chip. */
    getCreditRisk: (customerId) => ipcRenderer.invoke('customers:getCreditRisk', customerId),
    /** Returns khata_ledger entries for a customer. */
    getKhataLedger: (customerId) => ipcRenderer.invoke('customers:getKhataLedger', customerId),
    /** Records a customer cash repayment with FIFO allocation. Returns { success, ledgerId, newBalance } */
    recordRepayment: (customerId, amount, dateTime, notes) => ipcRenderer.invoke('customers:recordRepayment', customerId, amount, dateTime, notes),
    /** Full customer detail: { customer, ledger, invoices }. */
    getDetail: (customerId) => ipcRenderer.invoke('customers:getDetail', customerId),
    /** Renders the customer's khata ledger to a PDF and saves it via a native save dialog. */
    downloadKhataPdf: (customerId) => ipcRenderer.invoke('khata:downloadPdf', customerId),
    /** Builds the customer's khata ledger as an Excel workbook and saves it via a native save dialog. */
    downloadKhataExcel: (customerId) => ipcRenderer.invoke('khata:downloadExcel', customerId),
    /** Saves a free-text note on the customer profile. Returns { success }. */
    setNote: (customerId, notes) => ipcRenderer.invoke('customers:setNote', customerId, notes),
    /** Opens a native file picker and sets the customer's profile photo. Returns { success, dataUri?, canceled?, error? } */
    pickPhoto: (customerId) => ipcRenderer.invoke('customers:pickPhoto', customerId),
    /** Saves a photo captured live from the webcam (data URL from a canvas). Returns { success, dataUri?, error? } */
    saveCapturedPhoto: (customerId, dataUrl) => ipcRenderer.invoke('customers:saveCapturedPhoto', customerId, dataUrl),
    /** Deletes the customer's profile photo. Returns { success, error? } */
    removePhoto: (customerId) => ipcRenderer.invoke('customers:removePhoto', customerId),
    /** Additional phone numbers for a customer. */
    getPhones: (customerId) => ipcRenderer.invoke('customers:getPhones', customerId),
    /** Adds an extra phone number. Returns { success, error?, alreadyLinked? } */
    addPhone: (customerId, phone, label) => ipcRenderer.invoke('customers:addPhone', customerId, phone, label),
    /** Removes an extra phone number by its row id. */
    deletePhone: (phoneId) => ipcRenderer.invoke('customers:deletePhone', phoneId),
    /** Updates name/address; renaming re-checks name uniqueness. Returns { success, error? } */
    updateProfile: (customerId, patch) => ipcRenderer.invoke('customers:updateProfile', customerId, patch),
    /** Archives a customer as deceased (natural causes). treatment: 'FREEZE' | 'WRITE_OFF'. Returns { success, treatment?, writtenOff?, error? } */
    archive: (customerId, options) => ipcRenderer.invoke('customers:archive', customerId, options),
    /** Records a manual/legacy khata debt (no sale, no WAC/P&L impact). */
    addManualEntry: (customerId, data) => ipcRenderer.invoke('khata:addManualEntry', customerId, data),
    /** Records an advance/prepaid order (customer paid, delivery pending). */
    addAdvanceOrder: (customerId, data) => ipcRenderer.invoke('khata:addAdvanceOrder', customerId, data),
    /** Advance/prepaid orders for a customer. */
    getAdvanceOrders: (customerId) => ipcRenderer.invoke('khata:getAdvanceOrders', customerId),
    /** All PENDING advance/prepaid orders, across every customer. */
    getAllPendingAdvances: () => ipcRenderer.invoke('khata:getAllPendingAdvances'),
    /** Marks a pending advance order as fulfilled - clears it from Reminders. */
    markAdvanceFulfilled: (id) => ipcRenderer.invoke('khata:markAdvanceFulfilled', id),
    /** Customers with a negative running_balance - money/goods owed BY the shop. */
    getWeOweList: () => ipcRenderer.invoke('customers:getWeOweList'),
    /** Ranks customers by 'spend' | 'count' | 'loyalty'. */
    getTopCustomers: (sortBy, limit) => ipcRenderer.invoke('customers:getTopCustomers', sortBy, limit),
    /** Every real customer with lifetime totals + balance (Customers directory). */
    getAll: () => ipcRenderer.invoke('customers:getAll'),
    /** New-customer counts per month for the growth chart. */
    getGrowth: () => ipcRenderer.invoke('customers:getGrowth'),
    /** All customers + relationship edges for the Family & Relative Charts graph. */
    getFamilyGraph: () => ipcRenderer.invoke('customers:getFamilyGraph'),
    /** Links customerId to a relative by name - auto-registers them as a customer first if they don't exist yet. */
    linkRelative: (customerId, data) => ipcRenderer.invoke('customers:linkRelative', customerId, data),
    /** Adds/updates a relationship edge between two existing customers. */
    addRelationship: (customerId, targetCustomerId, relationshipType, isSuccessor) =>
      ipcRenderer.invoke('customers:addRelationship', customerId, targetCustomerId, relationshipType, isSuccessor),
    /** Removes a relationship edge (customerId -> targetCustomerId direction only). */
    removeRelationship: (customerId, targetCustomerId) => ipcRenderer.invoke('customers:removeRelationship', customerId, targetCustomerId),
  },

  // Invoices (Phase 5)
  invoices: {
    /** Creates full invoice atomically. Returns { success, invoiceId, invoiceNumber } */
    create: (invoiceData, lineItems) => ipcRenderer.invoke('invoices:create', invoiceData, lineItems),
    /** Records a payment against an outstanding invoice. Returns { success, newOutstanding } */
    recordPayment: (invoiceId, amount) => ipcRenderer.invoke('invoices:recordPayment', invoiceId, amount),
    /** Gets full invoice with line items for receipt. Returns { success, invoice } */
    get: (invoiceId) => ipcRenderer.invoke('invoices:get', invoiceId),
    /** Returns recent invoices for dashboard. Returns array */
    getRecent: (limit, typeFilter) => ipcRenderer.invoke('invoices:getRecent', limit, typeFilter),
    /** Returns today's invoices and totals for the Dashboard. */
    getToday: () => ipcRenderer.invoke('invoices:getToday'),
    /** Returns all outstanding invoices with promise dates for Reminders. */
    getReminders: () => ipcRenderer.invoke('invoices:getReminders'),
    /** Searches all invoices by number, customer name, or date. Returns array */
    searchHistory: (query, limit) => ipcRenderer.invoke('invoices:searchHistory', query, limit),
    /** Marks a scheduled delivery as delivered - clears it from Reminders. */
    markDelivered: (usin) => ipcRenderer.invoke('invoices:markDelivered', usin),
    /** Returns every sale invoice with customer info, for the Invoices management page. */
    getAllForManagement: () => ipcRenderer.invoke('invoices:getAllForManagement'),
    /** Renders an invoice to a clean A4 PDF and saves it via a native save dialog. Returns { success, filePath?, canceled?, error? } */
    downloadPdf: (usin) => ipcRenderer.invoke('invoices:downloadPdf', usin),
    /** Same invoice HTML as downloadPdf, returned directly for an in-app <iframe> preview - nothing is written to disk. */
    getPreviewHtml: (usin) => ipcRenderer.invoke('invoices:getPreviewHtml', usin),
    /** Current print_count + last print timestamp for one invoice. */
    getPrintStatus: (usin) => ipcRenderer.invoke('invoices:getPrintStatus', usin),
    /** Compiles a multi-invoice summary matrix for a custom date range. */
    getRangeStatement: (startDate, endDate) => ipcRenderer.invoke('invoices:getRangeStatement', startDate, endDate),
    /** Exports the custom-range statement to PDF via a native save dialog. */
    downloadRangeStatementPdf: (startDate, endDate) => ipcRenderer.invoke('invoices:downloadRangeStatementPdf', startDate, endDate),
    /** Exports the custom-range statement to Excel via a native save dialog. */
    downloadRangeStatementExcel: (startDate, endDate) => ipcRenderer.invoke('invoices:downloadRangeStatementExcel', startDate, endDate),
  },

  // Checkout (live cart preview)
  checkout: {
    /** Read-only total preview via the shared checkoutEngine. Returns
     *  { success, lines, subtotalExclTax, totalTax, totalDiscount, netPayable } */
    calculate: (lineItems) => ipcRenderer.invoke('checkout:calculate', lineItems),
  },

  // Estimates / Trial Orders (isolated from real sales - see estimateDao.js)
  estimates: {
    /** Logs a price estimate/trial order. No stock/khata/report side effects. */
    create: (estimateData, lineItems) => ipcRenderer.invoke('estimates:create', estimateData, lineItems),
    /** Recent estimates, newest first. */
    getRecent: (limit) => ipcRenderer.invoke('estimates:getRecent', limit),
    /** One estimate with parsed line items - for convert-to-sale. Returns { success, estimate?, error? } */
    get: (id) => ipcRenderer.invoke('estimates:get', id),
  },

  // Suppliers
  suppliers: {
    findOrCreate: (supplierData) => ipcRenderer.invoke('suppliers:findOrCreate', supplierData),
    search: (query) => ipcRenderer.invoke('suppliers:search', query),
    get: (id) => ipcRenderer.invoke('suppliers:get', id),
    getLedger: (supplierId) => ipcRenderer.invoke('suppliers:getLedger', supplierId),
    /** Returns scheduled installments across a supplier's stock-ins. */
    getInstallments: (supplierId) => ipcRenderer.invoke('suppliers:getInstallments', supplierId),
    recordRepayment: (supplierId, amount, dateTime, notes) => ipcRenderer.invoke('suppliers:recordRepayment', supplierId, amount, dateTime, notes),
    /** Returns all suppliers with running balances. */
    getBalances: () => ipcRenderer.invoke('suppliers:getBalances'),
    /** Opens a native file picker and sets the supplier's profile photo. Returns { success, dataUri?, canceled?, error? } */
    pickPhoto: (supplierId) => ipcRenderer.invoke('suppliers:pickPhoto', supplierId),
    /** Saves a photo captured live from the webcam (data URL from a canvas). Returns { success, dataUri?, error? } */
    saveCapturedPhoto: (supplierId, dataUrl) => ipcRenderer.invoke('suppliers:saveCapturedPhoto', supplierId, dataUrl),
  },

  // Thermal printer (Black Copper BC-87AC via OS printer driver)
  printer: {
    /** Lists OS-installed printers with a decoded hardware status code (or null = ready). */
    list: () => ipcRenderer.invoke('printer:list'),
    /** Interrogates the configured receipt printer's current connection state. */
    getStatus: () => ipcRenderer.invoke('printer:getStatus'),
    /** Silently prints an already-saved invoice's receipt to the configured printer (72mm, content-fitted). */
    print: (invoiceId) => ipcRenderer.invoke('printer:print', invoiceId),
    /** Same shared 72mm print path as print(); used by the invoice preview "Print Again" control. */
    printToHardware: (invoiceId) => ipcRenderer.invoke('print-to-hardware', invoiceId),
    /** Runs the identical print path with a short sample slip to verify the configured printer works. */
    test: () => ipcRenderer.invoke('printer:test'),
  },

  // Bank accounts, ledger, drafts/cheques, and draft reminders
  bank: {
    /** Creates a bank account. Returns { success, id?, error? } */
    createAccount: (data) => ipcRenderer.invoke('bank:createAccount', data),
    /** All accounts (active only by default) with transaction_count and last_activity. */
    getAccounts: (includeInactive) => ipcRenderer.invoke('bank:getAccounts', includeInactive),
    getAccount: (id) => ipcRenderer.invoke('bank:getAccount', id),
    /** Updates bank name/title/branch/type/notes - never the balance directly. */
    updateAccount: (id, patch) => ipcRenderer.invoke('bank:updateAccount', id, patch),
    /** Archives an account with transaction history, or hard-deletes an empty one. */
    deleteAccount: (id) => ipcRenderer.invoke('bank:deleteAccount', id),
    /** Records a deposit or withdrawal. Returns { success, id?, newBalance?, error? } */
    recordTransaction: (data) => ipcRenderer.invoke('bank:recordTransaction', data),
    /** Atomically moves money between two of the shop's own accounts. */
    recordTransfer: (data) => ipcRenderer.invoke('bank:recordTransfer', data),
    /** Voids a ledger entry via a linked contra-entry (transfers void both legs). Returns { success, reversalIds?, requiresOverride?, error? } */
    voidTransaction: (entryId, opts) => ipcRenderer.invoke('bank:voidTransaction', entryId, opts),
    /** Ledger for one account, newest first. filters: { startDate?, endDate?, entryType? } */
    getAccountTransactions: (accountId, filters) => ipcRenderer.invoke('bank:getAccountTransactions', accountId, filters),
    /** Total balance across active accounts + per-account and per-bank breakdown. */
    getBalanceSummary: () => ipcRenderer.invoke('bank:getBalanceSummary'),
    /** Balance-over-time series for one account (trailing `days` days). */
    getBalanceTrend: (accountId, days) => ipcRenderer.invoke('bank:getBalanceTrend', accountId, days),
    /** Records an in-flight bank draft/cheque (issued or received). */
    createDraft: (data) => ipcRenderer.invoke('bank:createDraft', data),
    getDrafts: (filters) => ipcRenderer.invoke('bank:getDrafts', filters),
    /** Marks a draft/cheque CLEARED / BOUNCED / CANCELLED (from PENDING). */
    updateDraftStatus: (id, status) => ipcRenderer.invoke('bank:updateDraftStatus', id, status),
    /** Pending drafts due within `days` days (default 14), including overdue. */
    getUpcomingDrafts: (days) => ipcRenderer.invoke('bank:getUpcomingDrafts', days),
    /** Quick unfinished reminder note, optionally tied to an account. */
    createReminderDraft: (data) => ipcRenderer.invoke('bank:createReminderDraft', data),
    getReminderDrafts: (status) => ipcRenderer.invoke('bank:getReminderDrafts', status),
    updateReminderDraft: (id, patch) => ipcRenderer.invoke('bank:updateReminderDraft', id, patch),
    deleteReminderDraft: (id) => ipcRenderer.invoke('bank:deleteReminderDraft', id),
    /** Renders a bank statement to PDF and saves it via a native save dialog. */
    downloadStatementPdf: (accountId, filters) => ipcRenderer.invoke('bank:downloadStatementPdf', accountId, filters),
    /** Builds a bank statement as an Excel workbook and saves it via a native save dialog. */
    downloadStatementExcel: (accountId, filters) => ipcRenderer.invoke('bank:downloadStatementExcel', accountId, filters),
  },

  // Employees: profiles, photos, leave log, payroll ledger
  employees: {
    /** Creates an employee profile. Returns { success, id?, error? } */
    create: (data) => ipcRenderer.invoke('employees:create', data),
    /** All employees (active only by default) with a `photo` data URI. */
    getAll: (includeInactive) => ipcRenderer.invoke('employees:getAll', includeInactive),
    get: (id) => ipcRenderer.invoke('employees:get', id),
    /** Updates profile fields - never the balance directly. */
    update: (id, patch) => ipcRenderer.invoke('employees:update', id, patch),
    /** Archives an employee with payroll history, or hard-deletes an empty profile. Always requires a non-empty reason and snapshots to past_employees first. */
    delete: (id, reason) => ipcRenderer.invoke('employees:delete', id, reason),
    /** Full past-employee archive (profile snapshot + metrics + exit reason), most recently removed first. */
    getPastEmployees: () => ipcRenderer.invoke('employees:getPastEmployees'),
    /** Opens a native file picker and sets the employee's profile photo. */
    pickPhoto: (employeeId) => ipcRenderer.invoke('employees:pickPhoto', employeeId),
    /** Logs an expected/scheduled leave period. */
    addLeave: (data) => ipcRenderer.invoke('employees:addLeave', data),
    getLeaves: (employeeId) => ipcRenderer.invoke('employees:getLeaves', employeeId),
    deleteLeave: (id) => ipcRenderer.invoke('employees:deleteLeave', id),
    /** Accrues salary owed (increases balance). Returns { success, id?, newBalance?, error? } */
    accrueSalary: (data) => ipcRenderer.invoke('employees:accrueSalary', data),
    /** Records a disbursement (decreases balance; can go negative = paid in advance). */
    recordPayment: (data) => ipcRenderer.invoke('employees:recordPayment', data),
    /** Signed bonus (+) or deduction (-) against the balance. */
    recordAdjustment: (data) => ipcRenderer.invoke('employees:recordAdjustment', data),
    /** Full chronological payroll ledger for one employee, newest first. */
    getLedger: (employeeId) => ipcRenderer.invoke('employees:getLedger', employeeId),
  },

  // Drivers: roster, photos, delivery history
  drivers: {
    /** All drivers (active only by default), with computed total_deliveries/total_earnings and a `photo` data URI. */
    getAll: (includeInactive) => ipcRenderer.invoke('drivers:getAll', includeInactive),
    get: (id) => ipcRenderer.invoke('drivers:get', id),
    update: (id, patch) => ipcRenderer.invoke('drivers:update', id, patch),
    delete: (id) => ipcRenderer.invoke('drivers:delete', id),
    pickPhoto: (driverId) => ipcRenderer.invoke('drivers:pickPhoto', driverId),
    /** Logs one delivery (manual backfill or otherwise) against a driver. */
    logDelivery: (data) => ipcRenderer.invoke('drivers:logDelivery', data),
    getDeliveries: (driverId) => ipcRenderer.invoke('drivers:getDeliveries', driverId),
    deleteDelivery: (id) => ipcRenderer.invoke('drivers:deleteDelivery', id),
  },

  // Rickshaw Trip Sheets & Commission Ledger
  trips: {
    /** Opens a trip sheet (fuel advance, expected collection, commission). Returns { success, id?, error? } */
    create: (data) => ipcRenderer.invoke('trips:create', data),
    /** Settles an open trip with the cash actually handed back. Returns { success, netHandover?, error? } */
    settle: (id, data) => ipcRenderer.invoke('trips:settle', id, data),
    /** Deletes an OPEN trip (mistaken entry). Settled trips are permanent. */
    delete: (id) => ipcRenderer.invoke('trips:delete', id),
    /** Trip sheets newest-first, optionally filtered by driver/status. */
    getAll: (filters) => ipcRenderer.invoke('trips:getAll', filters),
    /** Per-driver running balance sheet + grand totals (cash on road, commission, fuel). */
    getLedgerSummary: () => ipcRenderer.invoke('trips:getLedgerSummary'),
  },

  // Expenses & Bills
  expenses: {
    create: (data) => ipcRenderer.invoke('expenses:create', data),
    getAll: (filters) => ipcRenderer.invoke('expenses:getAll', filters),
    get: (id) => ipcRenderer.invoke('expenses:get', id),
    update: (id, patch) => ipcRenderer.invoke('expenses:update', id, patch),
    delete: (id) => ipcRenderer.invoke('expenses:delete', id),
    /** Opens a native file picker (pdf/image/doc) and attaches it to the expense. */
    pickAttachment: (expenseId) => ipcRenderer.invoke('expenses:pickAttachment', expenseId),
    /** Opens an attachment in the OS's own default viewer. */
    openAttachment: (attachmentPath) => ipcRenderer.invoke('expenses:openAttachment', attachmentPath),
    recordPayment: (data) => ipcRenderer.invoke('expenses:recordPayment', data),
    getPayments: (expenseId) => ipcRenderer.invoke('expenses:getPayments', expenseId),
    /** Unpaid/partial expenses due in exactly 2 days (ADVANCE) or exactly today (FINAL). */
    getDueReminders: () => ipcRenderer.invoke('expenses:getDueReminders'),
    getOverdue: () => ipcRenderer.invoke('expenses:getOverdue'),
    getCategoryBreakdown: () => ipcRenderer.invoke('expenses:getCategoryBreakdown'),
    getMonthlyTrend: (months) => ipcRenderer.invoke('expenses:getMonthlyTrend', months),
    /** Subscribes to the main process's startup/hourly deadline push. Returns an unsubscribe function. */
    onReminderPush: (cb) => {
      const listener = (_event, reminders) => cb(reminders);
      ipcRenderer.on('expenses:reminderPush', listener);
      return () => ipcRenderer.removeListener('expenses:reminderPush', listener);
    },
  },

  // System (clipboard / external links)
  system: {
    copyText: (text) => ipcRenderer.invoke('system:copyText', text),
    openExternal: (url) => ipcRenderer.invoke('system:openExternal', url),
  },

  // Crash diagnostics: renderer-side errors are appended to the same
  // diagnostics.log the main process writes to.
  diagnostics: {
    logRendererError: (payload) => ipcRenderer.invoke('diagnostics:logRendererError', payload),
  },

  // Notes (notepad)
  notes: {
    list: (category) => ipcRenderer.invoke('notes:list', category),
    create: (note) => ipcRenderer.invoke('notes:create', note),
    update: (id, note) => ipcRenderer.invoke('notes:update', id, note),
    delete: (id) => ipcRenderer.invoke('notes:delete', id),
    getCounts: () => ipcRenderer.invoke('notes:getCounts'),
    /** Cross-table scan of every notes/comment column (khata, supplier ledger, estimates, customers). */
    getAggregated: (opts) => ipcRenderer.invoke('notes:getAggregated', opts),
    updateKhataNote: (ledgerId, notes) => ipcRenderer.invoke('notes:updateKhataNote', ledgerId, notes),
    updateSupplierLedgerNote: (ledgerId, notes) => ipcRenderer.invoke('notes:updateSupplierLedgerNote', ledgerId, notes),
  },

  // Returns
  returns: {
    /** Creates a return invoice against an original sale. Returns { success, returnUsin, returnNumber } */
    create: (originalUsin, returnLines, customerId) => ipcRenderer.invoke('returns:create', originalUsin, returnLines, customerId),
    /** Returns recent return invoices. */
    getRecent: (limit) => ipcRenderer.invoke('returns:getRecent', limit),
  },

  // Stock In
  stockIn: {
    create: (stockInData, lineItems, installments) => ipcRenderer.invoke('stockIn:create', stockInData, lineItems, installments),
    getRecent: (limit) => ipcRenderer.invoke('stockIn:getRecent', limit),
  },

  // Receipt (Phase 5)
  receipt: {
    /** Generates receipt text + HTML preview for an invoice. Returns { success, text, html } */
    generate: (invoiceId) => ipcRenderer.invoke('receipt:generate', invoiceId),
  },
});