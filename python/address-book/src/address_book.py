import json


class AddressBook:
    """
    Address Book that manages a list of contacts
    """

    def __init__(self, contacts):
        self.contacts = contacts

    def add(self, name, email, phone):
        """ Add new contact """

        self.contacts.append({
            'name': name,
            'email': email,
            'phone': phone
        })

    def update(self, index, **kwargs):
        """ Update contact by index """

        self.contacts[index].update(**kwargs)

    def delete(self, index):
        """ Delete contact by index """

        self.contacts.pop(index)

    def lookup(self, **kwargs):
        """ Lookup contacts """

        return [contact for contact in self.contacts if
                all(value in contact[key] for key, value in kwargs.items())]

    @staticmethod
    def display_contacts(contacts):
        """ Display generic list of contacts """

        out = '\nNAME:\tE-MAIL:\tPHONE NUMBER:'
        for contact in contacts:
            out += '\n' + contact['name'] + '\t' + contact['email'] + '\t' + contact['phone']
        out += '\n'
        return out

    def __str__(self):
        """ Display contact information in a human readable way """

        return self.display_contacts(self.contacts)


def load_contacts():
    """ Load contacts from file """

    with open(filename, 'r') as f:
        content = f.read()

    return json.loads(content) if content else []


def save_contacts():
    """ Save contacts to file """

    with open(filename, 'w') as f:
        f.write(json.dumps(book.contacts))


def add_contact():
    """ Add a new contact to the address book """

    name = input('Name: ')
    email = input('E-mail: ')
    phone = input('Phone number: ')
    book.add(name, email, phone)


def update_contact():
    """ Update a contact from the address book """

    print('Which contact do you want to update:')
    for index, contact in enumerate(book.contacts, start=1):
        print('\t{0}. {1}'.format(index, contact['name']))

    contact_option = int(input('Enter your option [1-3]: '))
    if contact_option > len(book.contacts):
        print('Invalid contact.')
    else:
        index = contact_option - 1
        while True:
            print('What would you like to update:')
            print('\t1. Name')
            print('\t2. E-mail')
            print('\t3. Phone number')
            print('\t4. Back to menu')
            option = int(input('Enter your option [1-4]: '))

            if option == 1:
                name = input('Name: ')
                book.update(index, name=name)
            elif option == 2:
                email = input('E-mail: ')
                book.update(index, email=email)
            elif option == 3:
                phone = input('Phone number: ')
                book.update(index, phone=phone)
            elif option == 4:
                break
            else:
                print('Invalid option.')


def delete_contact():
    """ Delete a contact from the address book """

    print('Which contact do you want to delete:')
    for index, contact in enumerate(book.contacts, start=1):
        print('\t{0}. {1}'.format(index, contact['name']))

    option = int(input('Enter your option [1-3]: '))
    if option > len(book.contacts):
        print('Invalid contact.')
    else:
        index = option - 1
        contact = book.contacts[index]
        answer = input('Contact \'{0}\' will be deleted. Are you sure? [y/n]: '.format(contact['name']))
        if answer == 'y':
            book.delete(index)


def lookup_contacts():
    """ Lookup for contacts from the address book"""

    print('How would you like to search?')
    print('\t1. Name')
    print('\t2. E-mail')
    print('\t3. Phone number')
    option = int(input('Enter your option [1-3]: '))
    if option == 1:
        name = input('Name: ')
        print(book.display_contacts(book.lookup(name=name)))
    if option == 2:
        email = input('E-mail: ')
        print(book.display_contacts(book.lookup(email=email)))
    if option == 3:
        phone = input('Phone number: ')
        print(book.display_contacts(book.lookup(phone=phone)))
    else:
        print('Invalid option.')


if __name__ == '__main__':
    """
    A program to manage contacts
    A contact is a dict with keys name, email and phone number
    """

    # load the address book from the file
    filename = 'contacts.txt'

    # it is possible that the file does not exist
    # if that is the case, create it
    try:
        data = load_contacts()
    except FileNotFoundError:
        open(filename, mode='w').close()
        data = []

    book = AddressBook(contacts=data)

    # Start the interactive menu
    while True:
        print('What would you like to do?')
        print('\t1. Display contacts')
        print('\t2. Add new contact')
        print('\t3. Update contact')
        print('\t4. Delete contact')
        print('\t5. Lookup contacts')
        print('\t6. Exit')
        menu_option = int(input('Enter your option [1-6]: '))

        if menu_option == 1:
            print(book)
        elif menu_option == 2:
            add_contact()
        elif menu_option == 3:
            update_contact()
        elif menu_option == 4:
            delete_contact()
        elif menu_option == 5:
            lookup_contacts()
        elif menu_option == 6:
            print('Saving contacts ...')
            save_contacts()
            print('Bye.')
            break
        else:
            print('Invalid option.')
