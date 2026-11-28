import pymongo
import json
import re
from typing import List, Dict, Optional
from bs4 import BeautifulSoup

class ProductDatabase:
    def __init__(self, connection_string: str = "mongodb://localhost:27017/", db_name: str = "ecommerce"):
        """Initialize MongoDB connection"""
        self.client = pymongo.MongoClient(connection_string)
        self.db = self.client[db_name]
        self.collection = self.db.products

    def extract_asins_from_similar_item_html(self, html_str):
        if not html_str or not isinstance(html_str, str):
            return []
        
        try:
            soup = BeautifulSoup(html_str, "html.parser")
            asins = []
            
            # Look for ASIN patterns in href attributes
            links = soup.find_all("a", href=True)
            for link in links:
                href = link["href"]
                # Extract ASIN from Amazon product URLs
                match = re.search(r"/dp/([A-Z0-9]{10})", href)
                if match:
                    asins.append(match.group(1))
            
            return list(set(asins))  # Remove duplicates
        except Exception as e:
            print(f"Error parsing similar_item HTML: {e}")
            return []

    def create_similar_item_ids(self, product_data):
        """Create similar_item_ids field combining all similar product sources"""
        similar_item_ids = []
        
        # From also_buy field
        also_buy = product_data.get("also_buy", [])
        if isinstance(also_buy, list):
            similar_item_ids.extend([str(asin) for asin in also_buy if isinstance(asin, str)])
        
        # From also_view field  
        also_view = product_data.get("also_view", [])
        if isinstance(also_view, list):
            similar_item_ids.extend([str(asin) for asin in also_view if isinstance(asin, str)])
        
        # From similar_item HTML field
        similar_item_html = product_data.get("similar_item", "")
        if similar_item_html:
            parsed_asins = self.extract_asins_from_similar_item_html(similar_item_html)
            similar_item_ids.extend(parsed_asins)
        
        # Remove duplicates and return
        return list(set(similar_item_ids))

    def load_json_to_mongodb(self, json_file_path: str):
        """Load data from JSON file to MongoDB with similar_item_ids field"""
        print("Starting data migration from JSON to MongoDB...")
        
        # Clear existing data
        self.collection.delete_many({})
        print("Cleared existing data from MongoDB")
        
        products = []
        processed_count = 0
        
        with open(json_file_path, "r") as f:
            for line in f:
                try:
                    p = json.loads(line.strip())
                    
                    # Extract basic fields
                    brand = p.get("brand", "Unknown")
                    title = p.get("title", "No Title")
                    price = self.clean_price(p.get("price", ""))
                    
                    # Handle images
                    image = ""
                    if "imUrl" in p and p["imUrl"]:
                        image = p["imUrl"]
                    elif "imageURLHighRes" in p and isinstance(p["imageURLHighRes"], list) and p["imageURLHighRes"]:
                        image = p["imageURLHighRes"][0]
                    elif "imageURL" in p and isinstance(p["imageURL"], list) and p["imageURL"]:
                        image = p["imageURL"][0]
                    
                    # Only add product if at least one field exists
                    if title or brand or price or image:
                        # Create similar_item_ids field (MATCHING SEED.PY LOGIC)
                        similar_item_ids = self.create_similar_item_ids(p)
                        
                        product_doc = {
                            "title": title,
                            "brand": brand,
                            "price": price,
                            "image": image,
                            "description": p.get("description", "No description available"),
                            "categories": p.get("categories", []),
                            "feature": p.get("feature", "No features listed"),
                            "asin": p.get("asin", ""),
                            "main_cat": p.get("main_cat", ""),
                            "salesRank": p.get("salesRank", {}),
                            "related": p.get("related", {}),
                            "details": p.get("details", {}),
                            "tech1": p.get("tech1", ""),
                            "tech2": p.get("tech2", ""),
                            "similar_item": p.get("similar_item", ""),
                            "date": p.get("date", ""),
                            "also_buy": p.get("also_buy", []),
                            "also_view": p.get("also_view", []),
                            "similar_item_ids": similar_item_ids,  # NEW FIELD
                            "imageURL": p.get("imageURL", []),
                            "imageURLHighRes": p.get("imageURLHighRes", []),
                            "imUrl": p.get("imUrl", "")
                        }
                        products.append(product_doc)
                        processed_count += 1
                        
                        # Batch insert every 1000 products for better performance
                        if len(products) >= 1000:
                            self.collection.insert_many(products)
                            print(f"Inserted batch of {len(products)} products. Total processed: {processed_count}")
                            products = []
                            
                except json.JSONDecodeError as e:
                    print(f"Error parsing JSON line: {e}")
                    continue
        
        # Insert remaining products
        if products:
            self.collection.insert_many(products)
            print(f"Inserted final batch of {len(products)} products")
        
        print(f"Data migration completed! Total products inserted: {processed_count}")
        
        # Create indexes for better query performance
        self.create_indexes()

    def clean_price(self, raw_price):
        """Clean price field - only accept prices starting with dollar symbol"""
        if not raw_price:
            return "Not available"
        
        price_str = str(raw_price).strip()
        
        # Check if price starts with dollar symbol
        if price_str.startswith('$'):
            # Extract and validate the numeric part
            match = re.search(r'\$(\d+(?:,\d{3})*(?:\.\d{1,2})?)', price_str)
            if match:
                return match.group(0)  # Return the full match including $
        
        return "Not available"

    def create_indexes(self):
        """Create database indexes for better performance"""
        try:
            # Index on brand for search functionality
            self.collection.create_index("brand")
            # Index on title for search
            self.collection.create_index("title") 
            # Index on categories
            self.collection.create_index("categories")
            # Index on ASIN for fast lookups
            self.collection.create_index("asin")
            # Index on similar_item_ids for similarity queries
            self.collection.create_index("similar_item_ids")
            print("Database indexes created successfully")
        except Exception as e:
            print(f"Error creating indexes: {e}")

    def get_all_products(self) -> List[Dict]:
        """Get all products from MongoDB"""
        try:
            products = list(self.collection.find({}, {"_id": 0}))
            return products
        except Exception as e:
            print(f"Error fetching products: {e}")
            return []

    def search_products_by_brand(self, brand_query: str) -> List[Dict]:
        """Search products by brand name"""
        try:
            # Case-insensitive search using regex
            query = {"brand": {"$regex": brand_query, "$options": "i"}}
            products = list(self.collection.find(query, {"_id": 0}))
            return products
        except Exception as e:
            print(f"Error searching products: {e}")
            return []

    def get_products_paginated(self, skip: int = 0, limit: int = 30, brand_filter: str = None) -> List[Dict]:
        """Get products with pagination and optional brand filter"""
        try:
            query = {}
            if brand_filter:
                query = {"brand": {"$regex": brand_filter, "$options": "i"}}
            
            products = list(self.collection.find(query, {"_id": 0}).skip(skip).limit(limit))
            return products
        except Exception as e:
            print(f"Error fetching paginated products: {e}")
            return []

    def count_products(self, brand_filter: str = None) -> int:
        """Count total products with optional brand filter"""
        try:
            query = {}
            if brand_filter:
                query = {"brand": {"$regex": brand_filter, "$options": "i"}}
            
            return self.collection.count_documents(query)
        except Exception as e:
            print(f"Error counting products: {e}")
            return 0

    def get_product_by_index(self, products: List[Dict], index: int) -> Optional[Dict]:
        """Get a specific product by index from the products list"""
        if 0 <= index < len(products):
            return products[index]
        return None

    def close_connection(self):
        """Close MongoDB connection"""
        self.client.close()

# Migration script - run this once to migrate data
if __name__ == "__main__":
    db = ProductDatabase()
    db.load_json_to_mongodb("../meta_Appliances.json")
    db.close_connection()