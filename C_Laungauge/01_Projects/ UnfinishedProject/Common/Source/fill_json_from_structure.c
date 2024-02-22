#include <jansson.h>

typedef struct {
    int id;
    const char *name;
    double price;
} Product;

int main() {
    // Create a Product structure
    Product product;
    product.id = 123;
    product.name = "Sample Product";
    product.price = 49.99;

    // Create a JSON object and fill it with the structure data
    json_t *json_product = json_object();
    json_object_set(json_product, "id", json_integer(product.id));
    json_object_set(json_product, "name", json_string(product.name));
    json_object_set(json_product, "price", json_real(product.price));

    // Serialize the JSON object to a string
    char *json_string = json_dumps(json_product, JSON_COMPACT);

    // Print the JSON string
    printf("JSON Data:\n%s\n", json_string);

    // Clean up
    free(json_string);
    json_decref(json_product);

    return 0;
}

