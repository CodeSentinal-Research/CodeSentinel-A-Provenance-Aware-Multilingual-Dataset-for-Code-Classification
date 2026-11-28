// functions for employee module
import { errHandle } from '../handlers/error-handler.js';
import { ObjectId } from 'mongodb';

// CRUD operations
// create new employee func
export async function createEmployee(fname, lname, email, position, salary, department, collection) {
    const insertNewEmp = {
        first_name: fname,
        last_name: lname,
        email: email,
        position: position,
        salary: salary,
        date_of_joining: new Date(),
        department: department,
        created_at: new Date(),
        updated_at: new Date(),
    };

    try {
        const result = await collection.insertOne(insertNewEmp);
        return { _id: result.insertedId, ...insertNewEmp };
    } catch (e) {
        errHandle(null, 'Error creating new employee: ' + e);
    }
}

export async function readAllEmployees(collection) {
    try {
        // uses find method to return array with all employee docs found in db
        return await collection.find(
            {},
            // using mongodb syntax to exclude created_at and updated_at fields
            { projection: { created_at: 0, updated_at: 0 } }
        ).toArray();
    } catch (e) {
        errHandle(null, 'Error reading employees: ' + e);
        return [];
    }
}

// read employee by id func
export async function readEmpById(_id, collection) {
    try {
        return await collection.findOne(
            { _id: new ObjectId(_id) },
            { projection: { created_at: 0, updated_at: 0 } }
        );
    } catch (e) {
        errHandle(null, 'Error reading employee by id: ' + e);
    }
}

// update employee by id func
export async function updateEmployee(_id, fname, lname, email, position, salary, department, collection) {
    try {
        const result = await collection.updateOne(
            { _id: new ObjectId(_id) },
            {
                $set: {
                    first_name: fname,
                    last_name: lname,
                    email: email,
                    position: position,
                    salary: salary,
                    department: department,
                    updated_at: new Date(),
                },
            }
        );
        return result;
    } catch (e) {
        errHandle(null, 'Error updating employee: ' + e);
    }
}

// delete employee by id func
export async function deleteEmployee(_id, collection) {
    try {
        const result = await collection.deleteOne({ _id: new ObjectId(_id) });
        return result;
    } catch (e) {
        errHandle(null, 'Error deleting employee: ' + e);
    }
}

// search employees by department or position
export async function searchEmployees(field, value, collection) {
    try {
        // removing case sensitivity via regex
        const query = { [field]: new RegExp(`^${value}$`, 'i') };
        const projection = {
            first_name: 1,
            last_name: 1,
            email: 1,
            department: 1,
            position: 1,
        };

        const results = await collection.find(query, { projection }).toArray();
        return results;
    } catch (e) {
        errHandle(null, 'Error searching employee: ' + e);
    }
}