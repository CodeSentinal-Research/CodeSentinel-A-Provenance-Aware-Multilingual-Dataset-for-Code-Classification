import pyperclip
import re
import tkinter as tk
from tkinter import ttk, messagebox
from functools import lru_cache
import threading
import json
import os
import gc
import sys
from typing import Dict, List, Any, Optional

# Constants for configuration
# Updated to work with PyInstaller by using proper path detection
def get_config_path():
    """Get the appropriate path for the config file that works both in development and when compiled"""
    if getattr(sys, 'frozen', False):
        # If running as compiled executable (PyInstaller)
        application_path = os.path.dirname(sys.executable)
    else:
        # If running in a normal Python environment
        application_path = os.path.dirname(os.path.abspath(__file__))
    
    return os.path.join(application_path, "html_converter_config.json")

CONFIG_FILE = get_config_path()
DEFAULT_MAX_HISTORY = 20
UPDATE_INTERVAL = 100  # Milliseconds between GUI updates

# Use lru_cache to avoid recreating the dictionary repeatedly
@lru_cache(maxsize=1)
def create_html_entity_dict():
    """Create a dictionary mapping characters to their HTML entity codes."""
    # Basic Latin characters (A-Z, a-z)
    letters = {chr(i): f'&#{i};' for i in range(65, 91)}  # Uppercase
    letters.update({chr(i): f'&#{i};' for i in range(97, 123)})  # Lowercase
    
    # Numbers (0-9)
    numbers = {chr(i): f'&#{i};' for i in range(48, 58)}
    
    # Common symbols
    symbols = {
        ' ': '&#32;', '!': '&#33;', '"': '&quot;', '#': '&#35;',
        '$': '&#36;', '%': '&#37;', '&': '&amp;', "'": '&#39;',
        '(': '&#40;', ')': '&#41;', '*': '&#42;', '+': '&#43;',
        ',': '&#44;', '-': '&#45;', '.': '&#46;', '/': '&#47;',
        ':': '&#58;', ';': '&#59;', '<': '&lt;', '=': '&#61;',
        '>': '&gt;', '?': '&#63;', '@': '&#64;', '[': '&#91;',
        '\\': '&#92;', ']': '&#93;', '^': '&#94;', '_': '&#95;',
        '`': '&#96;', '{': '&#123;', '|': '&#124;', '}': '&#125;',
        '~': '&#126;'
    }
    
    # Combine all dictionaries
    return {**letters, **numbers, **symbols}

def convert_to_html_entities(text: str, entity_dict: Dict[str, str]) -> str:
    """Convert characters in text to their HTML entity codes."""
    return ''.join(entity_dict.get(char, char) for char in text)

def convert_from_html_entities(html_text: str) -> str:
    """Convert HTML entity codes back to regular characters."""
    return re.sub(r'&#(\d+);|&([a-z]+);', 
                 lambda m: chr(int(m.group(1))) if m.group(1) else 
                          {'quot': '"', 'amp': '&', 'lt': '<', 'gt': '>'}.get(m.group(2), f'&{m.group(2)};'), 
                 html_text)

class HTMLEntityConverterApp:
    def __init__(self, root: tk.Tk):
        self.root = root
        self.root.title("HTML Entity Converter")
        self.root.geometry("700x500")
        self.root.resizable(True, True)
        
        # Set style - use a more lightweight theme
        self.style = ttk.Style()
        try:
            self.style.theme_use('winnative')  # Use the most lightweight theme
        except tk.TclError:
            pass  # Fallback to default theme if not available
            
        self.style.configure("TButton", padding=5)
        self.style.configure("TFrame", padding=5)
        self.style.configure("TLabel", padding=3)
        
        # Create entity dictionary once
        self.html_entities = create_html_entity_dict()
        self.history: List[Dict[str, Any]] = []
        self.max_history = DEFAULT_MAX_HISTORY
        self.pending_updates = False
        
        # Load saved history and settings
        self.load_config()
        
        # Create GUI components
        self.create_widgets()
        
        # Register window close handler
        self.root.protocol("WM_DELETE_WINDOW", self.on_close)
        
        # Force garbage collection to free memory
        gc.collect()
        
    def create_widgets(self):
        # Use a PanedWindow for better memory management
        self.paned_window = ttk.PanedWindow(self.root, orient=tk.VERTICAL)
        self.paned_window.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Top frame for input and controls
        top_frame = ttk.Frame(self.paned_window)
        self.paned_window.add(top_frame, weight=1)
        
        # Mode selection - use less memory-intensive widgets
        mode_frame = ttk.Frame(top_frame)
        mode_frame.pack(fill=tk.X, pady=2)
        
        self.mode_var = tk.StringVar(value="encode")
        ttk.Radiobutton(mode_frame, text="Encode", variable=self.mode_var, value="encode").pack(side=tk.LEFT, padx=5)
        ttk.Radiobutton(mode_frame, text="Decode", variable=self.mode_var, value="decode").pack(side=tk.LEFT, padx=5)
        
        # Input frame
        input_frame = ttk.Frame(top_frame)
        input_frame.pack(fill=tk.BOTH, expand=True, pady=2)
        
        ttk.Label(input_frame, text="Input:").pack(side=tk.LEFT, anchor=tk.N)
        
        # Use a scrollbar with Text widget for better performance
        input_scroll = ttk.Scrollbar(input_frame)
        input_scroll.pack(side=tk.RIGHT, fill=tk.Y)
        
        self.input_text = tk.Text(input_frame, height=4, width=50, wrap=tk.WORD, 
                                  yscrollcommand=input_scroll.set)
        self.input_text.pack(fill=tk.BOTH, expand=True, side=tk.LEFT, padx=2)
        input_scroll.config(command=self.input_text.yview)
        
        # Buttons frame - more compact
        btn_frame = ttk.Frame(top_frame)
        btn_frame.pack(fill=tk.X, pady=2)
        
        convert_btn = ttk.Button(btn_frame, text="Convert", command=self.lazy_convert)
        convert_btn.pack(side=tk.LEFT, padx=5)
        
        clear_btn = ttk.Button(btn_frame, text="Clear", command=self.clear_input)
        clear_btn.pack(side=tk.LEFT, padx=5)
        
        # Output frame
        output_frame = ttk.Frame(top_frame)
        output_frame.pack(fill=tk.BOTH, expand=True, pady=2)
        
        ttk.Label(output_frame, text="Output:").pack(side=tk.LEFT, anchor=tk.N)
        
        # Use a scrollbar with Text widget for better performance
        output_scroll = ttk.Scrollbar(output_frame)
        output_scroll.pack(side=tk.RIGHT, fill=tk.Y)
        
        self.output_text = tk.Text(output_frame, height=4, width=50, wrap=tk.WORD, 
                                   yscrollcommand=output_scroll.set, state=tk.DISABLED)
        self.output_text.pack(fill=tk.BOTH, expand=True, side=tk.LEFT, padx=2)
        output_scroll.config(command=self.output_text.yview)
        
        copy_btn = ttk.Button(output_frame, text="Copy", command=self.copy_output)
        copy_btn.pack(side=tk.RIGHT, padx=2)
        
        # Bottom frame for history
        history_frame = ttk.LabelFrame(self.paned_window, text="History")
        self.paned_window.add(history_frame, weight=1)
        
        # History listbox with scrollbar - optimized for memory
        self.history_listbox_frame = ttk.Frame(history_frame)
        self.history_listbox_frame.pack(fill=tk.BOTH, expand=True)
        
        scrollbar = ttk.Scrollbar(self.history_listbox_frame)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        
        # Use single instead of browse selectmode
        self.history_listbox = tk.Listbox(self.history_listbox_frame, height=8, 
                                          width=80, selectmode=tk.SINGLE,
                                          exportselection=0)  # Prevent selection export to clipboard
        self.history_listbox.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        
        self.history_listbox.config(yscrollcommand=scrollbar.set)
        scrollbar.config(command=self.history_listbox.yview)
        
        self.history_listbox.bind("<<ListboxSelect>>", self.use_history_item)
        
        # Clear history button
        clear_history_btn = ttk.Button(history_frame, text="Clear History", 
                                       command=self.clear_history)
        clear_history_btn.pack(side=tk.BOTTOM, anchor=tk.E, padx=5, pady=2)
        
        # Status bar - lightweight
        self.status_var = tk.StringVar()
        self.status_bar = ttk.Label(self.root, textvariable=self.status_var, 
                                    relief=tk.SUNKEN, anchor=tk.W)
        self.status_bar.pack(side=tk.BOTTOM, fill=tk.X)
        
        # Initialize display
        self._update_history_display()
        
    def lazy_convert(self):
        """Delayed conversion to prevent multiple conversions in a short time."""
        if not self.pending_updates:
            self.pending_updates = True
            self.root.after(100, self._do_convert)
    
    def _do_convert(self):
        """Actually perform the conversion."""
        self.pending_updates = False
        self.convert()
    
    def convert(self):
        input_text = self.input_text.get("1.0", tk.END).strip()
        if not input_text:
            self.status_var.set("No input text provided")
            return
            
        mode = self.mode_var.get()
        
        # Create a lightweight thread for processing
        thread = threading.Thread(target=self._convert_thread, 
                                 args=(input_text, mode),
                                 daemon=True)  # Make thread daemon for cleanup
        thread.start()
    
    def _convert_thread(self, input_text: str, mode: str):
        try:
            if mode == "decode":
                result = convert_from_html_entities(input_text)
                action = "Decoded"
            else:
                result = convert_to_html_entities(input_text, self.html_entities)
                action = "Encoded"
                
            # Update UI components from main thread
            self.root.after(0, lambda: self._update_result(result, action, input_text, mode))
        except Exception as e:
            # Show error in main thread
            self.root.after(0, lambda: messagebox.showerror("Error", str(e)))
    
    def _update_result(self, result: str, action: str, input_text: str, mode: str):
        # Update output text
        self.output_text.config(state=tk.NORMAL)
        self.output_text.delete("1.0", tk.END)
        self.output_text.insert("1.0", result)
        self.output_text.config(state=tk.DISABLED)
        
        # Copy to clipboard
        pyperclip.copy(result)
        
        # Add to history - store only what's needed
        history_text = input_text[:30] + ('...' if len(input_text) > 30 else '')
        history_item = f"[{mode.upper()}] {history_text}"
        
        # Store both the display text and the result
        history_data = {
            "display": history_item,
            "result": result,
            "input": input_text,
            "mode": mode,
            "timestamp": None  # Could add timestamp if needed
        }
        
        # Add to history
        self.history.insert(0, history_data)
        
        # Keep history at a reasonable size
        if len(self.history) > self.max_history:
            self.history.pop()
            
        # Update history display
        self._update_history_display()
        
        # Update status
        self.status_var.set(f"{action} and copied to clipboard")
        
        # Save config after updating
        self.save_config()
    
    def _update_history_display(self):
        """Update history display with minimal resource usage."""
        self.history_listbox.delete(0, tk.END)
        for item in self.history:
            self.history_listbox.insert(tk.END, item["display"])
    
    def use_history_item(self, event):
        """Handle history item selection."""
        selection = self.history_listbox.curselection()
        if not selection:
            return
            
        index = selection[0]
        if 0 <= index < len(self.history):
            # Get the selected item's data
            selected = self.history[index]
            
            # You can choose to populate input with the original input
            self.input_text.delete("1.0", tk.END)
            self.input_text.insert("1.0", selected["input"])
            
            # Set the mode
            self.mode_var.set(selected["mode"])
            
            # Update output
            self.output_text.config(state=tk.NORMAL)
            self.output_text.delete("1.0", tk.END)
            self.output_text.insert("1.0", selected["result"])
            self.output_text.config(state=tk.DISABLED)
            
            # Copy to clipboard
            pyperclip.copy(selected["result"])
            self.status_var.set("Copied from history to clipboard")
    
    def clear_input(self):
        """Clear the input text."""
        self.input_text.delete("1.0", tk.END)
        
    def copy_output(self):
        """Copy output text to clipboard."""
        output = self.output_text.get("1.0", tk.END).strip()
        if output:
            pyperclip.copy(output)
            self.status_var.set("Output copied to clipboard")
        else:
            self.status_var.set("No output to copy")
    
    def clear_history(self):
        """Clear the history."""
        self.history = []
        self._update_history_display()
        self.save_config()
        self.status_var.set("History cleared")
    
    def load_config(self):
        """Load history and settings from the config file."""
        try:
            if os.path.exists(CONFIG_FILE):
                with open(CONFIG_FILE, 'r', encoding='utf-8') as f:
                    config = json.load(f)
                    
                # Get history with validation
                if "history" in config and isinstance(config["history"], list):
                    # Validate each history item
                    self.history = []
                    for item in config["history"]:
                        if all(key in item for key in ["display", "result", "input", "mode"]):
                            self.history.append(item)
                
                # Get max_history with validation
                if "max_history" in config and isinstance(config["max_history"], int):
                    self.max_history = max(5, min(100, config["max_history"]))
                    
        except (json.JSONDecodeError, IOError, OSError):
            # If there's an error loading, use defaults
            self.history = []
            self.max_history = DEFAULT_MAX_HISTORY
    
    def save_config(self):
        """Save history and settings to the config file."""
        try:
            # Create config object
            config = {
                "history": self.history,
                "max_history": self.max_history
            }
            
            # Save to file
            with open(CONFIG_FILE, 'w', encoding='utf-8') as f:
                json.dump(config, f, ensure_ascii=False, indent=2)
                
        except (IOError, OSError) as e:
            # Just log the error - don't bother the user
            print(f"Error saving config: {e}")
    
    def on_close(self):
        """Handle window closing."""
        self.save_config()
        
        # Clean up resources
        self.root.after_cancel(self.pending_updates) if self.pending_updates else None
        
        # Force garbage collection
        gc.collect()
        
        # Destroy the window
        self.root.destroy()

def main():
    # Create root with reduced overhead
    root = tk.Tk()
    root.option_add('*tearOff', False)  # Disable tearoff menus
    
    # Create app
    app = HTMLEntityConverterApp(root)
    
    # Start main loop
    root.mainloop()

if __name__ == "__main__":
    main()