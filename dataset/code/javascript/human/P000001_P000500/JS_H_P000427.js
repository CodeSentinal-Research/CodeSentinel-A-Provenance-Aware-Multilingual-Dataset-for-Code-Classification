/**
 * Example Search Hook — Amazon Product Advertising API
 *
 * This example shows how to query Amazon's PA-API v5 and return results
 * in the standard CLISHOP vendor product format.
 *
 * Setup:
 *   1. Sign up for Amazon Associates: https://affiliate-program.amazon.com
 *   2. Get PA-API credentials: https://webservices.amazon.com/paapi5/documentation/
 *   3. Set environment variables:
 *        AMAZON_ACCESS_KEY=your-access-key
 *        AMAZON_SECRET_KEY=your-secret-key
 *        AMAZON_PARTNER_TAG=your-tag-20
 *        AMAZON_MARKETPLACE=www.amazon.com  (or .co.uk, .de, etc.)
 *   4. npm install amazon-paapi
 *   5. Copy this file to hooks/search.js
 *
 * @param {object} context — see hooks/search.default.js for full documentation
 * @returns {Array} — products in standard vendor format
 */

// const amazonPaapi = require("amazon-paapi");

module.exports = async function search(context) {
  const { query, filters, delivery_address, limit } = context;

  // ── Uncomment and configure when you have Amazon PA-API credentials ──

  /*
  const commonParameters = {
    AccessKey: process.env.AMAZON_ACCESS_KEY,
    SecretKey: process.env.AMAZON_SECRET_KEY,
    PartnerTag: process.env.AMAZON_PARTNER_TAG,
    PartnerType: "Associates",
    Marketplace: process.env.AMAZON_MARKETPLACE || "www.amazon.com",
  };

  const requestParameters = {
    Keywords: query,
    SearchIndex: mapCategoryToSearchIndex(filters.category),
    ItemCount: Math.min(limit, 10), // PA-API max is 10 per request
    Resources: [
      "ItemInfo.Title",
      "ItemInfo.Features",
      "ItemInfo.ByLineInfo",
      "Offers.Listings.Price",
      "Offers.Listings.DeliveryInfo.IsFreeShippingEligible",
      "Offers.Listings.DeliveryInfo.IsPrimeEligible",
      "Offers.Listings.Availability.Type",
      "Images.Primary.Large",
    ],
  };

  // Apply price filter
  if (filters.min_price != null || filters.max_price != null) {
    requestParameters.MinPrice = filters.min_price ? Math.round(filters.min_price * 100) : undefined;
    requestParameters.MaxPrice = filters.max_price ? Math.round(filters.max_price * 100) : undefined;
  }

  // Apply brand filter
  if (filters.brand) {
    requestParameters.Brand = filters.brand;
  }

  try {
    const response = await amazonPaapi.SearchItems(commonParameters, requestParameters);
    const items = response.SearchResult?.Items || [];

    return items.map((item) => ({
      product_id: `amazon::${item.ASIN}`,
      title: item.ItemInfo?.Title?.DisplayValue || "Unknown",
      sku: item.ASIN,
      description: (item.ItemInfo?.Features?.DisplayValues || []).join(" "),
      price: {
        amount: (item.Offers?.Listings?.[0]?.Price?.Amount || 0).toFixed(2),
        currency: item.Offers?.Listings?.[0]?.Price?.Currency || "USD",
      },
      stock_available: item.Offers?.Listings?.[0]?.Availability?.Type === "Now" ? 1 : 0,
      images: item.Images?.Primary?.Large?.URL ? [item.Images.Primary.Large.URL] : [],
      tags: [],
      brand: item.ItemInfo?.ByLineInfo?.Brand?.DisplayValue || null,
      is_active: true,
      shipping: {
        free: item.Offers?.Listings?.[0]?.DeliveryInfo?.IsFreeShippingEligible || false,
        estimated_days: item.Offers?.Listings?.[0]?.DeliveryInfo?.IsPrimeEligible ? 2 : 5,
      },
      returns: { free: false, window_days: 30 },
      updated_at: new Date().toISOString(),
    }));
  } catch (err) {
    console.error("Amazon search error:", err.message);
    return [];
  }
  */

  // Placeholder — remove this and uncomment above when configured
  console.log(`[Amazon hook] Would search Amazon for: "${query}"`);
  return [];
};

/*
function mapCategoryToSearchIndex(category) {
  if (!category) return "All";
  const map = {
    electronics: "Electronics",
    books: "Books",
    clothing: "Fashion",
    home: "HomeAndKitchen",
    toys: "ToysAndGames",
    sports: "SportsAndOutdoors",
    beauty: "Beauty",
    food: "GroceryAndGourmetFood",
  };
  return map[category.toLowerCase()] || "All";
}
*/
